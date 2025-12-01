#include "InputManager.h"
#include <Novice.h>
#include <cstring> // memcpy用

char* InputManager::GetKeys()
{
    // 配列の先頭アドレスを返す
    return keys;
}

char* InputManager::GetPreKeys()
{
    return preKeys;
}

void InputManager::Update()
{
    // 1. 現在のフレームのキー入力を、前回のフレーム用変数にコピーする
    memcpy(preKeys, keys, 256);

    // 2. ここで新しいキー入力を取得する処理が必要です
    Novice::GetHitKeyStateAll(keys);

}