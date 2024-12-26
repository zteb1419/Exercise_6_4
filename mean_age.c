#include <stdio.h>
#include <stdlib.h>
#define P_NUM 4
/* MSB used as "Female" flag*/
#define FEM_FLAG 0b10000000

int main() {
    int ages[P_NUM];
    int cur, m_cnt = 0, f_cnt = 0, m_sum = 0, f_sum = 0;
    char s;
    

    for(int cnt = 0; cnt < P_NUM; cnt++) {
        printf("Input age: ");

        while(scanf("%d", &cur) != 1 || cur < 0 || cur > 100) {
            /* Next line is the (generally) accepted way to clear "garbage" from buffer*/
            for ( int ch; (ch = getchar()) != EOF && ch != '\n'; );
            printf("Invalid age! Try again: ");
        }

        for ( int ch; (ch = getchar()) != EOF && ch != '\n'; );
        printf("Male(m) / Female(f): ");
        while((scanf("%c", &s) != 1 || (s != 'm')) && s != 'f') {
            for ( int ch; (ch = getchar()) != EOF && ch != '\n'; );
            printf("Invalid Sex! Try again: ");
        }
        printf("Person %d, Age: %d, Sex: %c\n", cnt + 1, cur, s);
        ages[cnt] = (s=='m') ? cur:cur | FEM_FLAG;
        

    }
    for(int n = 0; n < P_NUM; n++) {
        if(ages[n] & FEM_FLAG) {
            f_cnt++; f_sum += (ages[n] & ~FEM_FLAG);
        } else {
            m_cnt++; m_sum += ages[n];
        }
    }

    printf("\nSAMPLE\nMen: %d, Women: %d\n", m_cnt, f_cnt);
 
    (f_cnt > 0)?printf("Mean age for women: %.1f\n", (float)f_sum/f_cnt):printf("No females in sample!\n");
    (m_cnt > 0)?printf("Mean age for men: %.1f\n", (float)m_sum/m_cnt):printf("No males in sample!\n");

}