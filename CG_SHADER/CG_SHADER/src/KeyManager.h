#pragma once

enum class KeyState
{
    NONE,//�ƹ��͵� �ƴѻ���
    PRESS, //�������ִ»���
    DOWN, //�ѹ�����
    UP, //Ű���� ���Ƕ�
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
    

    //������������
    bool Getbutton(unsigned char key) { return _states[static_cast<unsigned char>(key)] == KeyState::PRESS; }

    //��ó�� ��������
    bool GetbuttonDown(unsigned char key) { return _states[static_cast<unsigned char>(key)] == KeyState::DOWN; }

    //��ó�� �����ٰ� ����
    bool GetbuttonUp(unsigned char key) { return _states[static_cast<unsigned char>(key)] == KeyState::UP; }
    

    static void KeyboardCallback(unsigned char key, int x, int y);
    static void KeyboardUpCallback(unsigned char key, int x, int y);

    void Update();


private:
   KeyManager();
   static KeyState _states[256];
};



