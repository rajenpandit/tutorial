#include <cstdio>

class House{
public:
    int m_bhk;
    int m_numberOfFloors;
    int m_paintColor;

    House(int bhk, int numberOfFloors, int painColor){
        m_bhk = bhk;
        m_numberOfFloors = numberOfFloors;
        m_paintColor = painColor;
    }

    void paint(int color)
    {
        m_paintColor = color;
    }
    int getPaintColor(){
        return m_paintColor;
    }
    int numberOfFloors(){
        return m_numberOfFloors;
    }
    int bhk(){
        return m_bhk;
    }
};


int main(){
    House h1(4,2,1);  // 1:red 2:white 3:blue
    House h2(8,2,2);
    printf("h1:%d  h2:%d\n", h1.bhk(), h2.bhk());
    printf("Paint Color: h1:%d, h2:%d\n", h1.getPaintColor(), h2.getPaintColor());
    h1.paint(3);
    printf("Paint Color: h1:%d, h2:%d\n", h1.getPaintColor(), h2.getPaintColor());
}

