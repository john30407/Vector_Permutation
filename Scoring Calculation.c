#include<stdio.h>
#define V_LEN 6
#define C_LEN 5
#define R_LEN 4
#define AvB 5
#define AvC 1.67
#define AvD 1
#define BvC 1
#define BvD 5
#define CvD 0.2
#define WEIGHT1 0.2
#define WEIGHT2 0.3
#define WEIGHT3 0.15
#define WEIGHT4 0.35

//typedef enum categories{AvB, AvC, AvD, BvC, BvD, CvD}category; 
void ranking_score(int in_len, int result_len, float in[], float result[]);
void array_print(int len, float array[], int decimal_place);
void final_ranking_score(int in1_len, int in2_len, int in3_len, int in4_len, int result_len, float in1[], float in2[], float in3[], float in4[], float result[]);
float maxValue(float myArray[], int size);

int main(void) {
    
    //array of scores 
    float scores[C_LEN]={5, 1.67, 1, 0.6, 0.2};
    float cat1[V_LEN] = {AvB, AvC, AvD, BvC, BvD, CvD};
    float cat2[V_LEN] = {AvC, AvC, AvD, BvC, BvD, CvD};
    float cat3[V_LEN] = {AvD, AvC, AvD, BvC, BvD, CvD};
    float cat4[V_LEN] = {CvD, AvC, AvD, BvC, BvD, CvD};
    static float result1[R_LEN];
    static float result2[R_LEN];
    float result3[R_LEN];
    float result4[R_LEN];
    float final_result[R_LEN];
    int counter = 0;
    
    //take the ratings for each category of a criteria
    //generate a matrix of full pairwise rating 4x4, hardcoded to define value because IDE limitations in taking user input
        
    //generate a matrix to multiply rating matrix 4x1
        //TODO: formula for matrix  
    //product becomes category ranking matrix 4x1
    printf("Ratings for Each Category in Criteria 1: ");
    array_print(V_LEN, cat1, 2);
    ranking_score(V_LEN, R_LEN, cat1, result1);
    printf("Ranking Score for Criteria 1: ");
    array_print(R_LEN, result1, 3);
    
    printf("Ratings for Each Category in Criteria 2: ");
    array_print(V_LEN, cat2, 2);
    ranking_score(V_LEN, R_LEN, cat2, result2);
    printf("Ranking Score for Criteria 2: ");
    array_print(R_LEN, result2, 3);
    
    printf("Ratings for Each Category in Criteria 3: ");
    array_print(V_LEN, cat3, 2);
    ranking_score(V_LEN, R_LEN, cat3, result3);
    printf("Ranking Score for Criteria 3: ");
    array_print(R_LEN, result3, 3);
    
    printf("Ratings for Each Category in Criteria 4: ");
    array_print(V_LEN, cat4, 2);
    ranking_score(V_LEN, R_LEN, cat4, result4);
    printf("Ranking Score for Criteria 4: ");
    array_print(R_LEN, result4, 3);
   
    //sum up the category rankings with their weights appliied, produce final ranking  
    final_ranking_score(R_LEN,R_LEN,R_LEN,R_LEN,R_LEN,result1,result2,result3,result4,final_result);
    printf("FINAL SCORE:\n  A     B      C      D\n ");
    array_print(R_LEN, final_result,2);    

    return 0;
}


void array_print(int len, float array[], int decimal_place){ //decimal place 1-3
    if(decimal_place == 1){
        for(int i=0; i<len; i++)
            printf("%.1f  ", array[i]);
    }
    else if (decimal_place == 2){
        for(int i=0; i<len; i++)
            printf("%.2f  ", array[i]);
    }
    else if (decimal_place == 3){
        for(int i=0; i<len; i++)
            printf("%.3f  ", array[i]);
    }
    else if (decimal_place == 4){
        for(int i=0; i<len; i++)
            printf("%.4f  ", array[i]);
    }
    printf("\n");
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

void final_ranking_score(int in1_len, int in2_len, int in3_len, int in4_len, int result_len, float in1[], float in2[], float in3[], float in4[], float result[]){
    
    float max1=1, max2=1, max3=1, max4=1;
    max1 = maxValue(in1,in1_len);
    max2 = maxValue(in2,in2_len);
    max3 = maxValue(in3,in3_len);
    max4 = maxValue(in4,in4_len);
    
    for(int i=0; i<result_len;i++){
        result[i] = (in1[i]*WEIGHT1/max1 + in2[i]*WEIGHT2/max2 + in3[i]*WEIGHT3/max3 + in4[i]*WEIGHT4/max4)*100;
    }
    return 0;
}

float maxValue(float myArray[], int size) {
        float maxValue = myArray[0];
        for (int i = 0; i < size; i++) {
            if ( myArray[i] > maxValue ) {
                maxValue = myArray[i];
            }
        }
    return maxValue;
}
