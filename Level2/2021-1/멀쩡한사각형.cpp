using namespace std;

long long solution(int w,int h) {
    long long answer = 1; //for last chance
	double m1 = h, m2 = w;

	if (w > h){
		m1 = w; 
        m2 = h;
    }
	
	double angle = m2 / m1;
	for (int i = 1; i < m1; i++)
	{
		int plusdata = 1;
		plusdata += ((int)(m2*i / m1) + 1 < m2*(i+1) / m1 ) ? 1 : 0;	
		answer += plusdata;
	}

	answer = (m1 * m2) - answer;
	return answer;
}
