#include <stdio.h>
#include "Matrix1D.h"
#include "MoveSequence.h"

int main(int, char**) {
    MoveSequence msq;
    
    msq.appendLast(Point2D(3,2));
    msq.appendLast(Point2D(5,3));
    msq.appendLast(Point2D(7,4));
    msq.appendLast(Point2D(9,5));
    msq.appendFirst(Point2D(1,1));
    
    MoveSequence msq_shift;
    msq_shift.appendLast(Point2D(0,2));
    msq_shift.appendLast(Point2D(0,2));
    msq_shift.appendLast(Point2D(0,2));
    msq_shift.appendLast(Point2D(0,2));
    msq_shift.appendLast(Point2D(0,2));

    MoveSequence msq_final = msq + msq_shift;

    /*
    Expected output :
        msq_final : (1, 3) (3, 4) (5, 5) (7, 6) (9, 7)
    */
    printf("msq_final : ");
    for(int i = 0;i<msq_final.getLength();i++) printf("(%d, %d) ", msq_final.getValueAt(i).x, msq_final.getValueAt(i).y);
    printf("\n");

    return 0;
}
