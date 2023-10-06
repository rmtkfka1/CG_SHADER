#pragma once

enum class KeyState
{
    NONE,//아무것도 아닌상태
    PRESS, //누르고있는상태
    DOWN, //한번눌림
    UP, //키보드 자판땜
    END
};


class KeyManager
{
public:
    static KeyManager* GetInstance()
    {
        static KeyManager KM;
        return &KM;
    };
    

    //누르고있을때
    bool Getbutton(unsigned char key) { return _states[static_cast<unsigned char>(key)] == KeyState::PRESS; }

    //맨처음 눌렀을때
    bool GetbuttonDown(unsigned char key) { return _states[static_cast<unsigned char>(key)] == KeyState::DOWN; }

    //맨처음 눌렀다가 땔대
    bool GetbuttonUp(unsigned char key) { return _states[static_cast<unsigned char>(key)] == KeyState::UP; }


    static void KeyboardCallback(unsigned char key, int x, int y);
    static void KeyboardUpCallback(unsigned char key, int x, int y);

    void Update();


private:
   KeyManager();
   static KeyState _states[256];
};



