function multiplyMatriz(A, B) {
let M = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]
    ];

for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
        for (let k = 0; k < 3; k++) {
            M[i][j] += A[i][k] * B[k][j];
        }
    }
}
return M;
}

const mtzA = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];
const mtzB = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
];

console.table(multiplyMatriz(mtzA, mtzB));