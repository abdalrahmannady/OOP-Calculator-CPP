/*
pseudo code for the calculator project;
- Class for the Calculator;
- Enum for the operation type
- Private Varibales;
- Add function;
- subtract function;
- divide function;
- mulitiply function;
- print function;
- print Final Result function;
- clear function;
*/
#include <iostream>
using namespace std;
class clsCalculator {
private:
	enum enOperation
	{
		enAdd = 0,
		enSubtract = 1,
		enDivide = 2,
		enMultiply = 3,
		enClear = 4
	};

	float _Result=0;
	float _LastNumber = 0;
	enOperation _LastOperation = enClear;
	string _GetOperationName()
	{
		switch (_LastOperation)
		{
		case enAdd: return "Adding";
		case enSubtract: return "Subtracting";
		case enDivide: return "Dividing";
		case enMultiply: return "Multiplying";
		case enClear: return "Clearing";
		default: return "";
		}
	}
	bool _IsZero(float Number)
	{
		return (Number == 0);
	}
public:
	void Add(float num){
		_Result += num;
		_LastNumber = num;
		_LastOperation = enAdd;

	}
	void Subtract(float num) {
		_Result -= num;
		_LastNumber = num;
		_LastOperation = enSubtract;
	}
	void Multiply(float num) {
		_Result *= num;
		_LastNumber = num;
		_LastOperation = enMultiply;


	}
	void Divide(float num) {
		if (_IsZero(num)) {
			cout << "Cannot divide by zero! Defaulting to 1\n";
			num = 1;
		}
		_Result /= num;
		_LastNumber = num;
		_LastOperation = enDivide;

	}
	void Clear() {
		_Result =0;
		_LastNumber = 0;
		_LastOperation = enClear;
	}
	void PrintResult() {
		cout << "Result after " << _GetOperationName()<< " " << _LastNumber << " is : " << _Result << endl;
	}
	float GetFinalResults()
	{
		return _Result;
	}
};
int main() {
	clsCalculator CalculatiorObj;
	CalculatiorObj.Add(100);
	CalculatiorObj.PrintResult();
	CalculatiorObj.Subtract(20);
	CalculatiorObj.PrintResult();
	CalculatiorObj.Multiply(2);
	CalculatiorObj.PrintResult();
	CalculatiorObj.Divide(0);
	CalculatiorObj.PrintResult();
	CalculatiorObj.Clear();
	CalculatiorObj.PrintResult();
	return 0;

}
