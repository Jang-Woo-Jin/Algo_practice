#include <stdio.h>
#include <vector>
#include <algorithm>

#pragma warning (disable : 4996)

using namespace std;

class Room
{
public:
	int start;
	int end;

	Room(int start, int end) : start(start), end(end) {}

	bool operator < (const Room &comp) const {
		if (end == comp.end) return (start < comp.start);
		return (end < comp.end);
	}
};

int main() {
	int size;
	scanf("%d", &size);

	vector<Room> rooms;
	for (int i = 0; i < size; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		rooms.push_back(Room(start, end));
	}

	sort(rooms.begin(), rooms.end());
	
	int count = 1;
	int now = rooms[0].end;
	for (int i = 1; i < size; i++) {
		if (rooms[i].start >= now) {
			count++;
			now = rooms[i].end;
		}
	}
	if (size < 1) count = 0;
	printf("%d", count);
	return 0;
}