//
//  ModelEnter.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "ModelEnter.h"
#include "ResponseCommand.h"
#include "SymbolLoader.h"
ModelEnter::ModelEnter(){
    
}
void ModelEnter::DealResponseCommand(HMessage* mess)
{

    short prefix1 = mess->getShort();                 // 数据开始标志 固定为 -5000
    CCLOG("prefix------>%hd",prefix1);
    int modleId = mess->getInt();                    // 模块ID
    CCLOG("modleId----->%d",modleId);
    if(SymbolLoader::getInstance()->isHaveObject(modleId)){
        ResponseCommand* currentCommand = SymbolLoader::getInstance()->get(modleId);
        currentCommand->DealResponseCommand(mess);
    }
    
//    char modelSize = mes->get();//模块数量
//    for(int i=0;i<modelSize;i++){
//        int modelNum = mes->getShort();//模块号
//        CCLOG("modelNum === %d",modelNum);
//        if(SymbolLoader::getInstance()->isHaveObject(modelNum)){
//            ResponseCommand* currentCommand = SymbolLoader::getInstance()->get(modelNum);
//            currentCommand->DealResponseCommand(mes);
//        }
//    }
}