

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


#define min(a,b) (((a)<(b))?(a):(b))


int* getPair(int* nums1, int nums1Size, int* nums2, int nums2Size, int* index, int* sumPairTmp){
    
    int* out=NULL;
    int i;
    
    int minTmp= 2147483647;
    int minPairTmp=-1;
    
  
    
    
    //get sumPairTmp and its min
    
    for (i =0;i<nums1Size;i++){
        //printf("i=%d;\tindex[i]=%d;\n",i,index[i]);
        //printf("pair=%d,%d\n",nums1[i],nums2[index[i]]);
        if(index[i]>=nums2Size){
            
        }else{
            sumPairTmp[i]=nums1[i]+nums2[index[i]];
            if(sumPairTmp[i]<minTmp){
                minTmp=sumPairTmp[i];
                minPairTmp=i;
            }
        }
    }
    //get out pair update index 
    if(minPairTmp!=-1){
        out=malloc(sizeof(int)*2);
        out[0]=nums1[minPairTmp];
        out[1]=nums2[index[minPairTmp]];
        index[minPairTmp]++;
        //printf("========%d,%d\n",out[0],out[1]);
        
    }
    
    return(out);
    
    
    
    
}




int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    if((0==nums1Size)||(0==nums2Size)){ 
        *returnSize=0;
        *returnColumnSizes=NULL;
        return(NULL);}
    
   
    
    int i;
    int*  index   = calloc(nums1Size,sizeof(int));//0 all

    int*  sumPairTmp =malloc(sizeof(int)*nums1Size);
    
    int** result  = malloc(sizeof(int*)*k);
    
    int*  colSize = calloc(k,sizeof(int));//~0~all~~~~
    
    int   cntGetPair=0;
    
    
    for(i=0;i<k;i++){
        result[i]=getPair(nums1,nums1Size,nums2,nums2Size,index,sumPairTmp);
        if(result[i]!=NULL){
            colSize[i]=2;
            cntGetPair=cntGetPair+1;
            //printf("colSize%d\tcntGetPair=%d\n",colSize[i],cntGetPair);
        }
    }
    
    *returnSize=cntGetPair;
    *returnColumnSizes=colSize;
    free(index);
    free(sumPairTmp);
    
    return(result);
    
    
    
    
}
