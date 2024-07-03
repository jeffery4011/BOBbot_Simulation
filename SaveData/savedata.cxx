#include "savedata.h"
#include <torch/torch.h>
#include "BOBbot"

void savedata(BOBbot *parray){
    int L = parray.size();
    torch::Tensor tensorArray[];
    for (int i =0;i<L;i++){
        tensorArray.pushback(torch::tensor({BOBbotArray[i].pos.x,BOBbotArray[i].pos.y}));

    }
    // torch::tensor(BOB)
    
}