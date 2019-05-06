/** COMP0002 2018 Q4 */

/**
 * Q4(a)
 *
 *  input buffering:
 *      Store (accumulate) input into some array for later processing. If
 *      buffer reaches or is near its size limit, process and clear input stored
 *      in buffer.
 *  function definition:
 *      Supplying the implementation for a function's declaration.
 *  file scope:
 *      When a symbol's visibility is the same compilation unit after
 *      it has been declared.
 *  stderr:
 *      Standard error stream output, usually the console unless redirected.
 */

/**
 * Q4(b)
 *  A boolean value in C is represented by integers:
 *      0 = false
 *      1 = true
 *  Memory minimization can be achieved by compacting booleans into a bit-field:
 *  Perhaps a bit-field can be defined via an 1-byte (8-bits) `char` type, which
 *  allows 8 separate boolean values to be stored:
 *      char c1
 *            b7 b6 b5 b4 b3 b2 b1 b0
 *          [ 1  0  1  1  1  0  1  0  ]
 *  Then each bit of c1, e.g. b2 can be either true or false. Extracting the
 *  value involves bit-masks, e.g. to find the value of b4, use a bitmask:
 *      b7 b6 b5 b4 b3 b2 b1 b0
 *      0  0  0  1  0  0  0  0
 *      1  0  1  1  0  0  0  0  &
 *      =======================
 *      0  0  0  1  0  0  0  0
 *               ^
 *               |
 *               Value of b4 from the bit-field
 */
