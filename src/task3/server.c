#include "fcgi_stdio.h"
#include <stdlib.h>

int main() {
    while(FCGI_Accept() >= 0) 
        printf("Content-type: text/html\r\n"
            "\r\n"
                
            "<title>FastCGI Hello!</title>"    
            "<h1>FastCGI Hello world!</h1>");
}
