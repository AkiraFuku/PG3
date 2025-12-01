#pragma once

class InputManager
{
public:
    // 配列のポインタを返すように変更
    char* GetKeys();
    char* GetPreKeys();

    // 入力情報を更新する関数（これがないとキー入力が取れません）
    void Update(); 

private:
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };
};
