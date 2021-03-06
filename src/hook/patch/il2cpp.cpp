#include "src/hook/hook.h"
using namespace Sync;
using namespace Hook::Loaded;
using namespace Hook::Loaded::Patch::Const;

// 首次修改il2cpp
void Patch::FirstPatchIl2cpp()
{
    //三星条件选择器
    if (GetStateOrValue("三星", "", true))
        zzCodePatch(Address[0] + 0xA4, Down_x38);

    //触摸隐私部位
    zzCodePatch(Address[1] + 0xD4, NOP);
    zzCodePatch(Address[1] + 0x154, NOP);

    //解锁服装
    if (GetStateOrValue("解锁服装", "", false))
        zzCodePatch(Address[2] + 0xFC, NOP);

    //关闭强制刷新服装
    // zzCodePatch(Address[3] + 0x2F0, NOP); //TODO: 未修复为可用状态

#ifdef RELEASE
    RT("PT Done.");
#endif
}

// 循环修改il2cpp
void Patch::LoopPatchIl2cpp()
{
}
