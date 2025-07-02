#include <cmath>
#include <iostream>
#include <vector>

std::pair<int, int> spiralCoordinates(int n) {
    // Special case for the origin
    if (n == 0) {
        return {0, 0};
    }

    // Find which layer the point belongs to
    int k = static_cast<int>((std::sqrt(n) + 1) / 2);

    // Calculate the position at the start of the current layer
    int t = 4 * k * (k - 1) + 1;

    // Find which side of the layer we are on
    int side = (n - t) / k;
    int pos = (n - t) % k;

    // Calculate the coordinates based on which side of the spiral we're on
    if (side == 0) { // Right side
        return {k, pos - (k - 1)};
    } else if (side == 1) { // Bottom side
        return {k - pos - 1, -k};
    } else if (side == 2) { // Left side
        return {-k, -(k - pos - 1)};
    } else { // Top side (side == 3)
        return {-(k - pos - 1), k};
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        auto [x, y] = spiralCoordinates(n-1);
        std::cout << x << " " << y << std::endl;
    }
    return 0;
}