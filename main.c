#include<stdio.h>
#define V_LEN 6
#define C_LEN 5
#define R_LEN 4
//typedef enum categories{AvB, AvC, AvD, BvC, BvD, CvD}category; 

void array_print(int len, float array[], int decimal_place){ //decimal place 1-3
    if(decimal_place == 1){
        for(int i=0; i<len; i++)
            printf("%.1f ", array[i]);
    }
    else if (decimal_place == 2){
        for(int i=0; i<len; i++)
            printf("%.2f ", array[i]);
    }
    else if (decimal_place == 3){
        for(int i=0; i<len; i++)
            printf("%.3f ", array[i]);
    }
    else if (decimal_place == 4){
        for(int i=0; i<len; i++)
            printf("%.4f ", array[i]);
    }

}

void ranking_score(int in_len, int result_len, float in[], float result[]){
    float ca, cb, cc, cd;
    
    ca = 1 + 1/in[0] + 1/in[1] + 1/in[2];
    cb = 1 + in[0] + 1/in[3] + 1/in[4];
    cc = 1 + in[1] + in[3] + 1/in[5];
    cd = 1 + in[2] + in[4] + in[5];
    
    result[0] = (1/ca + in[0]/cb + in[1]/cc + in[2]/cd) / 4;
    result[1] = ((1/in[0])/ca + 1/cb + in[3]/cc + in[4]/cd) / 4;
    result[2] = ((1/in[1])/ca + (1/in[3])/cb + 1/cc + in[5]/cd) / 4;
    result[3] = ((1/in[2])/ca + (1/in[4])/cb + (1/in[5])/cc + 1/cd) / 4;

}

int main(void) {
    
    //array of scores 
    float scores[C_LEN]={5, 1.67, 1, 0.6, 0.2};
    float cat[V_LEN];
    float result[R_LEN];
    int counter = 0;
    for(int i=0; i<C_LEN; i++){
        cat[0]=scores[i];
        for(int j=0; j<C_LEN; j++){
            cat[1]=scores[j];
            for(int k=0; k<C_LEN; k++){
                cat[2]=scores[k];
                for(int a=0; a<C_LEN; a++){
                    cat[3]=scores[a];
                    for(int b=0; b<C_LEN; b++){
                        cat[4]=scores[b];
                        for(int c=0; c<C_LEN; c++){
                            cat[5]=scores[c];
                            ranking_score(V_LEN,R_LEN,cat,result);
                            array_print(R_LEN, result,3);
                            counter++;
                            printf("\n");
                        }
                    }
                }
            }
        }
    }
    //array_print(V_LEN, cat);

    printf("%d",counter);
    
    return 0;
}