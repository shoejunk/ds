import stk.ds;
import stk.log;

using namespace NStk::NDs;
using namespace NStk::NLog;

int main()
{
	TFixedVector<int, 10> aiVec;
	aiVec.Append(5);
	aiVec.Append(6);
	aiVec.Append(7);

	Log("Initial:\n");
	for (auto& i : aiVec)
	{
		Log("%d\n", i);
	}

	aiVec.RemoveAtOrdered(0);

	Log("RemoveAtOrdered(0):\n");
	for (auto& i : aiVec)
	{
		Log("%d\n", i);
	}

	aiVec.Append(8);
	aiVec.RemoveAtUnordered(0);
	Log("Append(8); RemoveAtUnordered(0):\n");
	for (auto& i : aiVec)
	{
		Log("%d\n", i);
	}

	return 0;
}
