
class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1 + n2, 0);
        
        // Multiply each digit of num2 by each digit of num1
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert the result vector to a string
        string resultStr;
        for (int num : result) {
            if (!(resultStr.empty() && num == 0)) { // Skip leading zeros
                resultStr.push_back(num + '0');
            }
        }
        
        return resultStr.empty() ? "0" : resultStr;
    }
};