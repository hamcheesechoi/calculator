#include <iostream>
#include <string>
#define interface struct

interface Cassett{
public:
    virtual void insertCasset() = 0;
    virtual void pushPlay() = 0;
    virtual void pushStop() = 0;
    virtual ~Cassett() = default;
};

interface MP3{
public:
    virtual void downloadMusic() = 0;
    virtual void mp3_play() = 0;
    virtual void mp3_stop() = 0;
    virtual ~MP3() = default;
};

class MYMY : public Cassett {
public:
    void insertCasset() override { std::cout << "카세트 삽입\n"; }
    void pushPlay()     override { std::cout << "푸시버튼\n"; }
    void pushStop()     override { std::cout << "푸쉬스탑버튼\n"; }
};

class EYE_Reaver : public MP3 {
public:
    void downloadMusic() override { std::cout << "음악 다운로드\n"; }
    void mp3_play()      override { std::cout << "음악시작\n"; }
    void mp3_stop()      override { std::cout << "음악 멈춰\n"; }
};

class adapter : public Cassett {
private:
    MP3& mp3;
public:
    adapter(MP3& mp3) : mp3{ mp3 } {}

    void insertCasset() override{
        mp3.downloadMusic();
    }
    void pushPlay() override {
        mp3.mp3_play();
    }
    void pushStop() override {
        mp3.mp3_stop();
    }
};
void run(Cassett& cs) {
    cs.insertCasset();
    cs.pushPlay();
    cs.pushStop();
}

int main() {
    // MP3로 변경
    EYE_Reaver er;
    adapter ad{ er };
    MYMY eye;
    run(ad);
}