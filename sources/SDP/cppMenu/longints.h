#ifndef CPPMENU
#define CPPMENU

class longints {
    public:
        void calc_longint(long scanned_num)
        {
            num=scanned_num;
            counted=0;
            while(num!=0)
            {
                temp=num%10;
                num=num/10;
                counted=counted+temp;
            }
        }

        long return_longint()
        {
            return counted;
        }

    private:
    protected:
        long num;
        int counted;
        long temp;
};

#endif // CPPMENU

