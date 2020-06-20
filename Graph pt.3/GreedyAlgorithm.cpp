/*kruskal algorithm
	1. 가중치가 가장 낮은 간선 추가
	2. 가중치가 가장 높은 간선 제거
	
T = null;
while((T가 n-1개 미만의 간선을 포함) && (E가 공백이 아님)) {
	E에서 최소 비용 간선 선택;
	선택된 간선 삭제;
	if 최소 비용 간선이 사이클을 만들지 않으면 T에 추가;
	else 최소 비용 간선 삭제;
}
if(T가 n-1개 미만의 간선 포함) cout << "신장 트리 없음" << endl;
*/

/*Prim algorithm
	시작 정점 선택 > 주변 간선 중 가중치 작은 것 연결
	
T = null;
for(T = null; T의 간선 수 < n-1; (u, v)를 T에 추가 {
	최소 비용 간선 (u, v)
	if(그런 간선 없음) break;
	v를 TV에 추가;
}
if(T의 간선 수가 n-1보다 작음) cout << "신장 트리 없음" << endl;
*/