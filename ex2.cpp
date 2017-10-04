#include <iostream>
#include <set>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

set<int> divide_vectors(vector<int> &data, int part_counts);

int main()
{
	srand(time(0));
	vector<int> data;

	int N = 1 + rand() % 30;
	for (int i = 0; i < N; ++i) {
		data.push_back(1 + rand() % 9);
	}
	for (int part = 1; part <= N; ++part) {

		set<int> res = divide_vectors(data, part);
		cout.setf(ios::fixed);
		int tabs = (N-part+1);
		cout<< setw(2) << part<< " parts: "<<setw(tabs);
		for (int i = 0; i < data.size(); ++i) {
			if (res.count(i)) {
				cout << "** ";
			}
			cout << data[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

set<int> divide_vectors(vector<int> &data, int part_counts)
{
	set<int> result;
	int vec_size = data.size();
	if (part_counts <= 2) {
		if(part_counts == 2) result.insert(floor(vec_size / part_counts));
	}
	else {
		if (vec_size%part_counts == 0) {
			int index = 0;
			int vec_part_size = vec_size / part_counts;
			for (int i = 0; i < part_counts; i++) {
				index += vec_part_size;
				result.insert(index);
			}
		}
		else {
			if (part_counts == 3) {
				int begin_part_size = floor((float)vec_size / part_counts);
				int vec_part_size = ceil((float)vec_size / part_counts);
				int index = begin_part_size;

				result.insert(index);
				for (int i = 0; i < part_counts - 2; i++) {
					index += vec_part_size;
					result.insert(index);
				}
			}
			else {
				vec_size -= 2;
				if (part_counts > 2) part_counts -= 2;

				while (((vec_size) % (part_counts)) != 0) {
					--vec_size;
				}
				int begin_part_size = floor((data.size() - (float)vec_size) / 2);
				int vec_part_size = vec_size / part_counts;
				int index = begin_part_size;

				result.insert(index);
				for (int i = 0; i < part_counts; i++) {
					index += vec_part_size;
					result.insert(index);
				}
			}
		}
	}
	return result;
}