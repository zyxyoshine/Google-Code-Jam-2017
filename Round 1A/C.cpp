#include<bits/stdc++.h>

using namespace std;

int play(int buff, int debuff){
	//printf("%d %d\n", buff, debuff);
	int H_d = Hd, A_d = Ad, H_k = Hk, A_k = Ak;
	int turn = 0;
	for (int i = 0; i < debuff; i++){
		bool boom = false;
		while (!boom){
			turn++;
			A_k -= D;
			H_d -= A_k;
			if (H_d <= 0) {
				A_k += D;
				H_d = Hd;
				if (Hd - (A_k) <= 0)
					return 0x7FFFFFFF;
			} else boom = true;

			if (A_k < 0)
				A_k = 0;
			STATUS
		}
	}
	for (int i = 0; i < buff; i++){
		bool boom = false;
		while (!boom){
			turn++;
			A_d += B;
			H_d -= A_k;
			if (H_d <= 0) {
				A_d -= B;
				H_d = Hd;
				i -= 1;
				if (Hd - 2*A_k <= 0)
					return 0x7FFFFFFF;
			} else boom = true;
			STATUS
		}
	}
	while (H_k > 0){
		turn++;
		//printf("%d %d\n", H_k, H_d);
		H_k -= A_d;
		if (H_k <= 0)
			return turn;
		H_d -= A_k;
		if (H_d <= 0){
			H_d = Hd;
			H_k += A_d;
			if (H_d - A_k <= 0)
				return 0x7FFFFFFF;
		}
		STATUS
	}
	return turn;
}
