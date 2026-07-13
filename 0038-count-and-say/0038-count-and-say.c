#pragma GCC optimize("O3")

char* countAndSay(int n) {
    static char buffers[2][10000];
    
    buffers[0][0] = '1';
    buffers[0][1] = '\0';
    
    int src = 0;
    int dst = 1;
    
    for (int i = 1; i < n; i++) {
        int readIdx = 0;
        int writeIdx = 0;
        
        while (buffers[src][readIdx] != '\0') {
            char val = buffers[src][readIdx];
            int count = 0;
            
            while (buffers[src][readIdx] == val) {
                count++;
                readIdx++;
            }
            
            buffers[dst][writeIdx++] = count + '0';
            buffers[dst][writeIdx++] = val;
        }
        buffers[dst][writeIdx] = '\0';
        
        src = 1 - src;
        dst = 1 - dst;
    }
    
    return buffers[src];
}