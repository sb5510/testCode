//给定一个 n × n 的二维矩阵表示一个图像。将图像顺时针旋转 90 度。
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
	//先转置矩阵，即matrix[i][j]变为matrix[j][i]
        for(int i = 0;i<matrix[0].size();i++)
        {
            for(int j = i;j<matrix[0].size();j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
	//再把矩阵按纵向中轴翻转
        for(int i = 0;i<matrix[0].size();i++)
        {
            for(int j = 0;j<matrix[0].size()/2;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[0].size()-1-j];
                matrix[i][matrix[0].size()-1-j] = temp;
            }
        }
    }
};
