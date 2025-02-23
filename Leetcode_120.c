int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int row = triangleSize - 2; row >= 0; row--) {
        for (int col = 0; col < triangleColSize[row]; col++) {
            triangle[row][col] += (triangle[row + 1][col] < triangle[row + 1][col + 1])
                                      ? triangle[row + 1][col]
                                      : triangle[row + 1][col + 1];
        }
    }
    return triangle[0][0];
}

