#include "UnlimitedIntApp.h"

UnlimitedIntApp::UnlimitedIntApp(int size): num(new UnlimitedInt(size))
{

}

void UnlimitedIntApp::setSize(int size)
{
    if (num->getSize() == size)
    {
        return;
    }
    delete num;
    num = new UnlimitedInt(size);
}

UnlimitedIntApp::~UnlimitedIntApp()
{
    delete num;
}
