#include <iostream>
#include <iomanip>  //iomanip에 setprecision()이 존재
using namespace std;
int main() {
    int C = 0, N = 0;   // 테스트 케이스의 수와 학생의 수
    cin >> C;
    for (int i = 0; i < C; i++) {   // 테스트 케이스 수만큼 반복
        cin >> N;
        int score[1000] = { 0 }, sum = 0;   // N명의 점수를 담을 배열과 점수의 합계
        double avg = 0.00;      // 평균
        for (int j = 0; j < N; j++) {
            cin >> score[j];
            sum += score[j];    // 점수의 총합을 구하고,
        }
        avg = (double)sum / N;  // 평균을 도출
        int count = 0;  // 평균을 넘는 학생을 셀 변수
        for (int j = 0; j < N; j++) {
            if (avg < score[j]) {
                count++;    // 평균이 넘는 학생이 나타날 때마다 1씩 증가
            }
        }
        // (평균이 넘는 학생 수 / 전체 학생 수) * 100
        cout << fixed << setprecision(3) << (double)count * 100 / N << "%" << endl;
        // fixed : 소수점을 고정해서 표현, 소수점 아래부터 출력을 지정
        // setprecision(n) : 가장 큰 자릿수부터 n자리를 출력, fixed가 있을 시에 소수점 아래 n자리 출력
        // (자료형)변수 : 형 변환 ex) (double)count = int형 변수인 count를 double형으로 변환
    }
    return 0;
}