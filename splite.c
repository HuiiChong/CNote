# CNote

void splite(int points[], int start, int end, int ran)
{
    int len = end-start+1;
    
    if(len%2==0){
        //偶数个元素
        if(ran==(len/2-1+start)){
            
            for(int i=start;i<=ran;i++){
                points[i] ^= points[(end+1)-(ran-i+1)];
                points[(end+1)-(ran-i+1)] ^= points[i];
                points[i] ^= points[(end+1)-(ran-i+1)];
            }
            
        }else if(ran<(len/2-1+start)){
            
            for(int i=start;i<=ran;i++){
                points[i] ^= points[(end+1)-(ran-i+1)];
                points[(end+1)-(ran-i+1)] ^= points[i];
                points[i] ^= points[(end+1)-(ran-i+1)];
            }
            
            splite(points, start, end-(ran-start+1), ran);
            
        }else{
            
            for (int i=ran+1; i<=end; i++) {
                points[i] ^= points[i-(ran-start+1)];
                points[i-(ran-start+1)] ^= points[i];
                points[i] ^= points[i-(ran-start+1)];
            }
            
            splite(points, start+(end-ran), end, ran);
            
        }
    }else{
        //奇数个元素
        if((ran-start+1)<(end-ran)){
            
            for(int i=start;i<=ran;i++){
                points[i] ^= points[(end+1)-(ran-i+1)];
                points[(end+1)-(ran-i+1)] ^= points[i];
                points[i] ^= points[(end+1)-(ran-i+1)];
            }
            
            splite(points, start, end-(ran-start+1), ran);
            
        }else{
            
            for (int i=ran+1; i<=end; i++) {
                points[i] ^= points[i-(ran-start+1)];
                points[i-(ran-start+1)] ^= points[i];
                points[i] ^= points[i-(ran-start+1)];
            }
            
            splite(points, start+(end-ran), end, ran);
            
        }
    }
}
