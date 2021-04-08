     /*   int n = wallPositions.size();
        int m = wallHeights.size();
        int max = 0;

        for (int i=0; i<n-1; i++) {
            if (wallPositions[i]<wallPositions[i+1]-1) {
                // We have a gap
                int heightDiff = abs(wallHeights[i+1] - wallHeights[i]);
                int gapLen = wallPositions[i+1] - wallPositions[i] - 1;
                int localMax = 0;
                if (gapLen > heightDiff) {
                    int low = std::max(wallHeights[i+1], wallHeights[i]) + 1;
                    int remainingGap = gapLen - heightDiff - 1;
                    localMax = low + remainingGap/2;

                } else {
                    localMax = std::min(wallHeights[i+1], wallHeights[i]) + gapLen;
                }

                max = std::max(max, localMax);
            }
        }

        return max;
        */