#include<iostream>
using namespace std;

class SortingAndSparseMatrix {
public:
    // Bubble Sort
    void bubbleSort(int arr[], int n) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    // Insertion Sort
    void insertionSort(int arr[], int n) {
        for(int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Quick Sort Helpers
    void quickSort(int arr[], int low, int high) {
        if(low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    // Merge Sort Helpers
    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];

        for(int i = 0; i < n1; i++) L[i] = arr[l + i];
        for(int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while(i < n1) arr[k++] = L[i++];
        while(j < n2) arr[k++] = R[j++];
    }

    void mergeSort(int arr[], int l, int r) {
        if(l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    // Display Array
    void display(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Sparse Matrix Addition
    void addSparse(int mat1[][3], int mat2[][3]) {
        int result[100][3], k = 1;
        if(mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1]) {
            cout << "Matrix dimensions do not match!\n";
            return;
        }

        int i = 1, j = 1;
        result[0][0] = mat1[0][0];
        result[0][1] = mat1[0][1];

        while(i <= mat1[0][2] && j <= mat2[0][2]) {
            if(mat1[i][0] == mat2[j][0] && mat1[i][1] == mat2[j][1]) {
                result[k][0] = mat1[i][0];
                result[k][1] = mat1[i][1];
                result[k][2] = mat1[i][2] + mat2[j][2];
                i++; j++; k++;
            }
            else if((mat1[i][0] < mat2[j][0]) || 
                   (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
                result[k][0] = mat1[i][0];
                result[k][1] = mat1[i][1];
                result[k][2] = mat1[i][2];
                i++; k++;
            }
            else {
                result[k][0] = mat2[j][0];
                result[k][1] = mat2[j][1];
                result[k][2] = mat2[j][2];
                j++; k++;
            }
        }

        while(i <= mat1[0][2]) result[k][0] = mat1[i][0], result[k][1] = mat1[i][1], result[k][2] = mat1[i][2], i++, k++;
        while(j <= mat2[0][2]) result[k][0] = mat2[j][0], result[k][1] = mat2[j][1], result[k][2] = mat2[j][2], j++, k++;

        result[0][2] = k - 1;
        cout << "Resultant Sparse Matrix (Triplet Form):\n";
        for(int x = 0; x < k; x++) {
            cout << result[x][0] << " " << result[x][1] << " " << result[x][2] << endl;
        }
    }

    // Sparse Matrix Multiplication - Placeholder
    void multiplySparse(int mat1[][3], int mat2[][3]) {
        cout << "Sparse matrix multiplication is complex in triplet form.\n";
        cout << "Consider converting to full matrix format before multiplication.\n";
    }
};

int main() {
    SortingAndSparseMatrix program;
    int choice, n, arr[100];

    cout << "Enter number of elements for sorting: ";
    cin >> n;
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout << "\nMenu:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Quick Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Add Two Sparse Matrices\n";
        cout << "6. Multiply Two Sparse Matrices\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                program.bubbleSort(arr, n);
                cout << "Sorted Array: ";
                program.display(arr, n);
                break;
            case 2:
                program.insertionSort(arr, n);
                cout << "Sorted Array: ";
                program.display(arr, n);
                break;
            case 3:
                program.quickSort(arr, 0, n - 1);
                cout << "Sorted Array: ";
                program.display(arr, n);
                break;
            case 4:
                program.mergeSort(arr, 0, n - 1);
                cout << "Sorted Array: ";
                program.display(arr, n);
                break;
            case 5: {
                int mat1[10][3] = {{3,3,3},{0,0,1},{1,2,2},{2,1,3}};
                int mat2[10][3] = {{3,3,2},{0,0,2},{1,2,4}};
                program.addSparse(mat1, mat2);
                break;
            }
            case 6: {
                int mat1[10][3] = {{2,2,2},{0,1,3},{1,0,5}};
                int mat2[10][3] = {{2,2,2},{0,1,4},{1,0,6}};
                program.multiplySparse(mat1, mat2);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}
