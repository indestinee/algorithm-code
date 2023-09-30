const int M = 100000;
class MinStack {
public:
    int a[M], b[M], cnt;
    MinStack(){cnt=0;}
    void push(int x) {
        b[cnt+1] = x;
        if( cnt && x > a[cnt] )
            x = a[cnt];
        a[++cnt] = x;
    }
    void pop() {
        cnt --;
    }

    int top() {
        return b[cnt];
    }

    int getMin() {
        return a[cnt];
    }
};
