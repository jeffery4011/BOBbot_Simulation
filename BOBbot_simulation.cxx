#include "BOBbot.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

__global__ void advanceBOBbots(float dt, BOBbot * pArray, int nBOBbots)
{
	int idx = threadIdx.x + blockIdx.x*blockDim.x;
	if(idx < nBOBbots)
	{
		pArray[idx].advance(dt);
	}
}

int main(int argc, char ** argv)
{
	cudaError_t error;
	int n = 1000000;
	if(argc > 1)	{ n = atoi(argv[1]);}     // Number of BOBbots
	if(argc > 2)	{	srand(atoi(argv[2])); } // Random seed


	BOBbot * pArray = new BOBbot[n];
	BOBbot * devPArray = NULL;
	cudaMalloc(&devPArray, n*sizeof(BOBbot));
	cudaDeviceSynchronize(); error = cudaGetLastError();
	

	cudaMemcpy(devPArray, pArray, n*sizeof(BOBbot), cudaMemcpyHostToDevice);
	cudaDeviceSynchronize(); error = cudaGetLastError();
	if (error != cudaSuccess)
  	{
  	printf("2 %s\n",cudaGetErrorString(error));
  	exit(1);
  	}

	for(int i=0; i<100; i++)
	{
		float dt = (float)rand()/(float) RAND_MAX; // Random distance each step
		advanceBOBbots<<< 1 +  n/256, 256>>>(dt, devPArray, n);
		error = cudaGetLastError();
		if (error != cudaSuccess)
    	{
    	printf("3 %s\n",cudaGetErrorString(error));
    	exit(1);
    	}

		cudaDeviceSynchronize();
	}
	cudaMemcpy(pArray, devPArray, n*sizeof(BOBbot), cudaMemcpyDeviceToHost);

	v3 totalDistance(0,0,0);
	v3 temp;
	for(int i=0; i<n; i++)
	{
		temp = pArray[i].getTotalDistance();
		totalDistance.x += temp.x;
		totalDistance.y += temp.y;
		totalDistance.z += temp.z;
	}
	float avgX = totalDistance.x /(float)n;
	float avgY = totalDistance.y /(float)n;
	float avgZ = totalDistance.z /(float)n;
	float avgNorm = sqrt(avgX*avgX + avgY*avgY + avgZ*avgZ);
	printf(	"Moved %d BOBbots 100 steps. Average distance traveled is |(%f, %f, %f)| = %f\n",
					n, avgX, avgY, avgZ, avgNorm);
	return 0;
}