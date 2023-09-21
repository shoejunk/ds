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
	aiVec.RemoveAtOrdered(0);
	Log("%d, %d\n", aiVec[0], aiVec[1]);
	aiVec.Append(8);
	aiVec.RemoveAtUnordered(0);
	Log("%d, %d\n", aiVec[0], aiVec[1]);
	return 0;
}
