#include <stdio.h>
int num = 0;
void m_coloring(int, int, int, int (*)[], int *);
int promising(int, int, int (*)[], int *);
int main(){
	int n;
	int i,j;
	printf("정점의 개수 : ");
	scanf("%d",&n);
	int W[n+1][n+1];
	int vcolor[n+1];
	printf("(연결되있으면 : 1, 아니면 : 0입력)\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("W[%d][%d] = ",i,j);
			scanf("%d",&W[i][j]);
		}
	}
	int c = 0;
	int m = 1;
	while(1){
		for(i=1;i<=m;i++){
			vcolor[1] = i;
			m_coloring(1,n,m,W,vcolor);
		}
		if(num > 0){
			break;
		}
		m++;
	}
	printf("최소 색의 수 = %d\n",m);
	printf("조합 수 = %d\n",num);
	return 0;
}
void m_coloring(int i, int n, int m, int (*W)[n+1], int *vcolor){
	int color;
	int a,b,c = 0;
	b = promising(i,n,W,vcolor);
	if(b == 1){
		if(i==n){
			for(a=1;a<=n;a++){
				printf("%d ",vcolor[a]);
			}
			printf("\n");
			num++;
		}
		else{
			for(color = 1; color <=m;color++){
				vcolor[i+1] = color;
				m_coloring(i+1,n,m,W,vcolor);
			}
		}
	}
}
int promising(int i, int n, int (*W)[n+1],int *vcolor){
	int j;
	int switch1;
	switch1 = 1;
	j=1;
	while(j<i && switch1 == 1){
		if(W[i][j] == 1 && vcolor[i] == vcolor[j]){
			switch1 = 0;
		}
		j++;
	}
	return switch1;
}
