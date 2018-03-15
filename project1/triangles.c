
# include <stdio.h>
# include <stdlib.h> 
# include <time.h>
# include <errno.h>
# include <limits.h> 


int main ( int argc, char **argv) {
    
    if (argc <= 1){
        printf("ERROR: program needs at least one command line argument\n\n");
        return 0; 
    }
    
    int i = 0; 
    for (i = 1; i < argc; ++i) { 
        errno = 0; 
        long l = strtol(argv[i], 0 , 10);
        if (errno) {
            printf("ERROR: could not convert %s to a number.\n\n", argv[i]); 
        }
        if ( l > (long)INT_MAX || l < (long)INT_MIN )  {
            printf("ERROR: number is too large/small, should be 32bits.\n\n");
        }
        int n = (int) l; 
        
        unsigned a = n &  0x000003FF; 
        unsigned b = (n & 0x000ffc00) >>10;
        unsigned c = (n & 0x3ff00000) >>20; 
        
        //printf ("n = %08X\n", n);  
        //printf ("a = %08X\n", a);  
        //printf ("b = %08X\n", b);  
        //printf ("c = %08X\n", c);  
        
        
        printf ("\nn = %d\n", n);  
        printf ("a = %d\n", a);  
        printf ("b = %d\n", b);  
        printf ("c = %d\n", c);  
        
        if (a>=b && a>=c && a <= (b+c) ) printf("valid");
        else if (b>=a && b>=c &&  b <= (a+c) ) printf("valid");
        else if (c>=a && c>=b &&  c <= (a+b) ) printf("valid");
        else printf("invalid"); 
        
        printf("\n"); 
    }
    return 0; 
}
