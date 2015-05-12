# CNote
# 随机切割数组：扑克中的随机切牌算法（10个元素的循环次数在5-9次之间）
void splite(int points[], int start, int end, int rand)
{
    int len = end-start+1;
    
    if(len%2==0){
        //偶数个元素
        if(rand==(len/2-1+start)){
            
            for(int i=start;i<=rand;i++){
                points[i] ^= points[(end+1)-(rand-i+1)];
                points[(end+1)-(rand-i+1)] ^= points[i];
                points[i] ^= points[(end+1)-(rand-i+1)];
            }
            
        }else if(rand<(len/2-1+start)){
            
            for(int i=start;i<=rand;i++){
                points[i] ^= points[(end+1)-(rand-i+1)];
                points[(end+1)-(rand-i+1)] ^= points[i];
                points[i] ^= points[(end+1)-(rand-i+1)];
            }
            
            splite(points, start, end-(rand-start+1), rand);
            
        }else{
            
            for (int i=rand+1; i<=end; i++) {
                points[i] ^= points[i-(rand-start+1)];
                points[i-(rand-start+1)] ^= points[i];
                points[i] ^= points[i-(rand-start+1)];
            }
            
            splite(points, start+(end-rand), end, rand);
            
        }
    }else{
        //奇数个元素
        if((rand-start+1)<(end-rand)){
            
            for(int i=start;i<=rand;i++){
                points[i] ^= points[(end+1)-(rand-i+1)];
                points[(end+1)-(rand-i+1)] ^= points[i];
                points[i] ^= points[(end+1)-(rand-i+1)];
            }
            
            splite(points, start, end-(rand-start+1), rand);
            
        }else{
            
            for (int i=rand+1; i<=end; i++) {
                points[i] ^= points[i-(rand-start+1)];
                points[i-(rand-start+1)] ^= points[i];
                points[i] ^= points[i-(rand-start+1)];
            }
            
            splite(points, start+(end-rand), end, rand);
            
        }
    }
}
