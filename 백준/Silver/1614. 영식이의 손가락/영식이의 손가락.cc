#include <stdio.h>

int main() {
    long long hf=0, num=0; 
    scanf("%lld\n%lld", &hf, &num);
    
    long long count=0;
    
    if (hf==1) count=num*8; 
    else if (hf==5) count=num*8+4;
    else if (hf==3) count=num*4+2; 
    else if (hf==2) {
        if (num%2==0) count=num*4+1; 
        if (num%2!=0) count=num*4+3;
    }
    else {
        if (num%2==0) count=num*4+3;
        if (num%2!=0) count=num*4+1;
    }
    printf("%lld", count);
}