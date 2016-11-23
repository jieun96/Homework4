#include <stdio.h>
int num = 0;   //조합 수
void m_coloring(int, int, int, int (*)[], int *);  //색을 지정해주는 함수
int promising(int, int, int (*)[], int *);  //지정한 색이 만나는 다른 지역과 같은지 검사하는 함수
int main(){
	int n = 25;  //도시의 수
	int i,j;
	int W[n+1][n+1];   //도시의 연결 표시
	int vcolor[n+1];   //칠할 색 저장
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){	
			W[i][j] = 0;   //모두 0으로 초기화
		}
	}
	for(i=1;i<=n;i++){  //서울시의 지도 저장
		for(j=1;j<=n;j++){	
			if(i==1&&(j==2||j==3||j==5)){   //은평구와 연결된 도시
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==2&&(j==3||j==4||j==16||j==17)){   //종로구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==3&&(j==4||j==5)){   //서대문구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==4&&(j==5||j==11||j==15)){   //중구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==5&&(j==6||j==9||j==11)){   //마포구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==6&&(j==7||j==9)){  //강서구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==7&&(j==8||j==9)){   //양천구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==8&&(j==9||j==10||j==13)){   //구로구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==9&&(j==11||j==12)){   //영등포구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==10&&j==13){   //금천구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==11&&(j==12||j==14||j==15||j==23)){   //용산구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==12&&(j==13||j==14)){   //동작구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==13&&j==14){    //관악구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==14&&j==23){   //서초구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==15&&(j==16||j==22||j==23)){    //성동구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==16&&(j==17||j==21||j==22)){    //동대문구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==17&&(j==18||j==20||j==21)){    //성북구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==18&&(j==19||j==20)){    //강북구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==19&&j==20){   //도봉구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==20&&j==21){    //노원구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==21&&j==22){    //중량구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==22&&(j==23||j==24||j==25)){   //광진구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==23&&j==24){    //강남구
				W[i][j] = 1;
				W[j][i] = 1;
			}
			if(i==24&&j==25){   //송파구
				W[i][j] = 1;
				W[j][i] = 1;
			}
		}
	}
	int m = 1;   //최소 색의 수
	while(1){
		for(i=1;i<=m;i++){  
			vcolor[1] = i;   //처음 도시의 색
			m_coloring(1,n,m,W,vcolor);
		}
		if(num > 0){    //조합이 가능할 경우
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
	if(b == 1){    //인접한 지역이 다른 색일경우
		if(i==n){   //모든 지역을 칠했으면
			num++;  //조합 수 1증가
		}
		else{    //아닐경우
			for(color = 1; color <=m;color++){    //모든 색에 대하여
				vcolor[i+1] = color;   //다음 지역 색 지정
				m_coloring(i+1,n,m,W,vcolor);   //그 지역에 색이 적합한지 확인
			}
		}
	}
}
int promising(int i, int n, int (*W)[n+1],int *vcolor){
	int j;
	int switch1;   //색이 적합하면 1, 아니면 0
	switch1 = 1;
	j=1;
	while(j<i && switch1 == 1){
		if(W[i][j] == 1 && vcolor[i] == vcolor[j]){    //인접한 지역인데 색이 같으면
			switch1 = 0;
		}
		j++;
	}
	return switch1;
}
