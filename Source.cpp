#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	cout << "Enter the number of cities : ";
	int n;
	cin >> n;
	int paths[100][100];
	cout << endl << "Enter the distances between cities (if there is no route between two cities enter -1)" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				paths[i][j] = -1;
			else if (i < j)
			{
				cout << endl << "Enter the distance between city " << i + 1 << " and city " << j + 1 << " : ";
				cin >> paths[i][j];
			}
			else
				paths[i][j] = paths[j][i];
		}

	cout << endl << endl << "Enter Starting city : ";
	int start;
	cin >> start;
	start--;

	int distances[100];
	bool visited[100];
	int previusCity[100];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		previusCity[i] = -1;
		distances[i] = 987654321;
	}
	distances[start] = 0;
	while (true)
	{
		int minDistance = 987654321, closestCity = -1;
		for (int i = 0; i < n; i++)
			if (!visited[i])
			{
				if (distances[i] < minDistance)
				{
					minDistance = distances[i];
					closestCity = i;
				}
			}

		if (closestCity == -1)
			break;

		visited[closestCity] = true;
		for (int j = 0; j < n; j++)
		{
			if (visited[j])
				continue;
			if (paths[closestCity][j] != -1)
				if (paths[closestCity][j] + distances[closestCity] < distances[j])
				{
					distances[j] = paths[closestCity][j] + distances[closestCity];
					previusCity[j] = closestCity;
				}
		}
	}

	cout << endl << endl << "Enter Destination city : ";
	int end;
	cin >> end;
	int Destination = end;
	end--;
	cout << endl << endl << "Distance = " << distances[end];
	if (end == start)
	{
		_getch();
		return 0;
	}
	int path[100];
	int i = 0;
	for (; i < n; i++)
	{
		path[i] = previusCity[end];
		end = path[i];
		if (end == start)
			break;
	}
	cout << endl << endl << "Route : ";
	for (int j = i; j >= 0; j--)
	{
		cout << path[j] + 1 << " -> ";
	}
	cout << Destination;

	_getch();
	return 0;
}