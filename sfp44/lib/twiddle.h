#include "sfp.hh"
double FN1024_REAL[1024] = {\
1.0000,1.0000,1.0000,1.0000,  1.0000,1.0000,0.9999,0.9998, \
1.0000,0.9999,0.9997,0.9993,  1.0000,0.9998,0.9993,0.9985, \
1.0000,0.9997,0.9988,0.9973,  1.0000,0.9995,0.9981,0.9958, \
1.0000,0.9993,0.9973,0.9939,  1.0000,0.9991,0.9963,0.9917, \
1.0000,0.9988,0.9952,0.9892,  1.0000,0.9985,0.9939,0.9863, \
1.0000,0.9981,0.9925,0.9831,  1.0000,0.9977,0.9909,0.9796, \
1.0000,0.9973,0.9892,0.9757,  1.0000,0.9968,0.9873,0.9715, \
1.0000,0.9963,0.9853,0.9670,  1.0000,0.9958,0.9831,0.9621, \
1.0000,0.9952,0.9808,0.9569,  1.0000,0.9946,0.9783,0.9514, \
1.0000,0.9939,0.9757,0.9456,  1.0000,0.9932,0.9729,0.9395, \
1.0000,0.9925,0.9700,0.9330,  1.0000,0.9917,0.9670,0.9262, \
1.0000,0.9909,0.9638,0.9191,  1.0000,0.9901,0.9604,0.9117, \
1.0000,0.9892,0.9569,0.9040,  1.0000,0.9883,0.9533,0.8960, \
1.0000,0.9873,0.9495,0.8876,  1.0000,0.9863,0.9456,0.8790, \
1.0000,0.9853,0.9415,0.8701,  1.0000,0.9842,0.9373,0.8609, \
1.0000,0.9831,0.9330,0.8514,  1.0000,0.9820,0.9285,0.8416, \
1.0000,0.9808,0.9239,0.8315,  1.0000,0.9796,0.9191,0.8211, \
1.0000,0.9783,0.9142,0.8105,  1.0000,0.9770,0.9092,0.7995, \
1.0000,0.9757,0.9040,0.7883,  1.0000,0.9743,0.8987,0.7769, \
1.0000,0.9729,0.8932,0.7652,  1.0000,0.9715,0.8876,0.7532, \
1.0000,0.9700,0.8819,0.7410,  1.0000,0.9685,0.8761,0.7285, \
1.0000,0.9670,0.8701,0.7157,  1.0000,0.9654,0.8640,0.7028, \
1.0000,0.9638,0.8577,0.6895,  1.0000,0.9621,0.8514,0.6761, \
1.0000,0.9604,0.8449,0.6624,  1.0000,0.9587,0.8382,0.6485, \
1.0000,0.9569,0.8315,0.6344,  1.0000,0.9551,0.8246,0.6201, \
1.0000,0.9533,0.8176,0.6055,  1.0000,0.9514,0.8105,0.5908, \
1.0000,0.9495,0.8032,0.5758,  1.0000,0.9476,0.7958,0.5607, \
1.0000,0.9456,0.7883,0.5453,  1.0000,0.9436,0.7807,0.5298, \
1.0000,0.9415,0.7730,0.5141,  1.0000,0.9395,0.7652,0.4982, \
1.0000,0.9373,0.7572,0.4822,  1.0000,0.9352,0.7491,0.4660, \
1.0000,0.9330,0.7410,0.4496,  1.0000,0.9308,0.7327,0.4331, \
1.0000,0.9285,0.7242,0.4164,  1.0000,0.9262,0.7157,0.3996, \
1.0000,0.9239,0.7071,0.3827,  1.0000,0.9215,0.6984,0.3656, \
1.0000,0.9191,0.6895,0.3484,  1.0000,0.9167,0.6806,0.3311, \
1.0000,0.9142,0.6716,0.3137,  1.0000,0.9117,0.6624,0.2962, \
1.0000,0.9092,0.6532,0.2785,  1.0000,0.9066,0.6438,0.2608, \
1.0000,0.9040,0.6344,0.2430,  1.0000,0.9013,0.6249,0.2251, \
1.0000,0.8987,0.6152,0.2071,  1.0000,0.8960,0.6055,0.1891, \
1.0000,0.8932,0.5957,0.1710,  1.0000,0.8904,0.5858,0.1528, \
1.0000,0.8876,0.5758,0.1346,  1.0000,0.8848,0.5657,0.1163, \
1.0000,0.8819,0.5556,0.0980,  1.0000,0.8790,0.5453,0.0797, \
1.0000,0.8761,0.5350,0.0613,  1.0000,0.8731,0.5246,0.0429, \
1.0000,0.8701,0.5141,0.0245,  1.0000,0.8670,0.5035,0.0061, \
1.0000,0.8640,0.4929,-0.0123,  1.0000,0.8609,0.4822,-0.0307, \
1.0000,0.8577,0.4714,-0.0491,  1.0000,0.8546,0.4605,-0.0674, \
1.0000,0.8514,0.4496,-0.0858,  1.0000,0.8481,0.4386,-0.1041, \
1.0000,0.8449,0.4276,-0.1224,  1.0000,0.8416,0.4164,-0.1407, \
1.0000,0.8382,0.4052,-0.1589,  1.0000,0.8349,0.3940,-0.1770, \
1.0000,0.8315,0.3827,-0.1951,  1.0000,0.8280,0.3713,-0.2131, \
1.0000,0.8246,0.3599,-0.2311,  1.0000,0.8211,0.3484,-0.2489, \
1.0000,0.8176,0.3369,-0.2667,  1.0000,0.8140,0.3253,-0.2844, \
1.0000,0.8105,0.3137,-0.3020,  1.0000,0.8068,0.3020,-0.3195, \
1.0000,0.8032,0.2903,-0.3369,  1.0000,0.7995,0.2785,-0.3542, \
1.0000,0.7958,0.2667,-0.3713,  1.0000,0.7921,0.2549,-0.3883, \
1.0000,0.7883,0.2430,-0.4052,  1.0000,0.7846,0.2311,-0.4220, \
1.0000,0.7807,0.2191,-0.4386,  1.0000,0.7769,0.2071,-0.4551, \
1.0000,0.7730,0.1951,-0.4714,  1.0000,0.7691,0.1830,-0.4876, \
1.0000,0.7652,0.1710,-0.5035,  1.0000,0.7612,0.1589,-0.5194, \
1.0000,0.7572,0.1467,-0.5350,  1.0000,0.7532,0.1346,-0.5505, \
1.0000,0.7491,0.1224,-0.5657,  1.0000,0.7451,0.1102,-0.5808, \
1.0000,0.7410,0.0980,-0.5957,  1.0000,0.7368,0.0858,-0.6104, \
1.0000,0.7327,0.0736,-0.6249,  1.0000,0.7285,0.0613,-0.6391, \
1.0000,0.7242,0.0491,-0.6532,  1.0000,0.7200,0.0368,-0.6670, \
1.0000,0.7157,0.0245,-0.6806,  1.0000,0.7114,0.0123,-0.6940, \
1.0000,0.7071,0.0000,-0.7071,  1.0000,0.7028,-0.0123,-0.7200, \
1.0000,0.6984,-0.0245,-0.7327,  1.0000,0.6940,-0.0368,-0.7451, \
1.0000,0.6895,-0.0491,-0.7572,  1.0000,0.6851,-0.0613,-0.7691, \
1.0000,0.6806,-0.0736,-0.7807,  1.0000,0.6761,-0.0858,-0.7921, \
1.0000,0.6716,-0.0980,-0.8032,  1.0000,0.6670,-0.1102,-0.8140, \
1.0000,0.6624,-0.1224,-0.8246,  1.0000,0.6578,-0.1346,-0.8349, \
1.0000,0.6532,-0.1467,-0.8449,  1.0000,0.6485,-0.1589,-0.8546, \
1.0000,0.6438,-0.1710,-0.8640,  1.0000,0.6391,-0.1830,-0.8731, \
1.0000,0.6344,-0.1951,-0.8819,  1.0000,0.6296,-0.2071,-0.8904, \
1.0000,0.6249,-0.2191,-0.8987,  1.0000,0.6201,-0.2311,-0.9066, \
1.0000,0.6152,-0.2430,-0.9142,  1.0000,0.6104,-0.2549,-0.9215, \
1.0000,0.6055,-0.2667,-0.9285,  1.0000,0.6006,-0.2785,-0.9352, \
1.0000,0.5957,-0.2903,-0.9415,  1.0000,0.5908,-0.3020,-0.9476, \
1.0000,0.5858,-0.3137,-0.9533,  1.0000,0.5808,-0.3253,-0.9587, \
1.0000,0.5758,-0.3369,-0.9638,  1.0000,0.5708,-0.3484,-0.9685, \
1.0000,0.5657,-0.3599,-0.9729,  1.0000,0.5607,-0.3713,-0.9770, \
1.0000,0.5556,-0.3827,-0.9808,  1.0000,0.5505,-0.3940,-0.9842, \
1.0000,0.5453,-0.4052,-0.9873,  1.0000,0.5402,-0.4164,-0.9901, \
1.0000,0.5350,-0.4276,-0.9925,  1.0000,0.5298,-0.4386,-0.9946, \
1.0000,0.5246,-0.4496,-0.9963,  1.0000,0.5194,-0.4605,-0.9977, \
1.0000,0.5141,-0.4714,-0.9988,  1.0000,0.5088,-0.4822,-0.9995, \
1.0000,0.5035,-0.4929,-0.9999,  1.0000,0.4982,-0.5035,-1.0000, \
1.0000,0.4929,-0.5141,-0.9997,  1.0000,0.4876,-0.5246,-0.9991, \
1.0000,0.4822,-0.5350,-0.9981,  1.0000,0.4768,-0.5453,-0.9968, \
1.0000,0.4714,-0.5556,-0.9952,  1.0000,0.4660,-0.5657,-0.9932, \
1.0000,0.4605,-0.5758,-0.9909,  1.0000,0.4551,-0.5858,-0.9883, \
1.0000,0.4496,-0.5957,-0.9853,  1.0000,0.4441,-0.6055,-0.9820, \
1.0000,0.4386,-0.6152,-0.9783,  1.0000,0.4331,-0.6249,-0.9743, \
1.0000,0.4276,-0.6344,-0.9700,  1.0000,0.4220,-0.6438,-0.9654, \
1.0000,0.4164,-0.6532,-0.9604,  1.0000,0.4108,-0.6624,-0.9551, \
1.0000,0.4052,-0.6716,-0.9495,  1.0000,0.3996,-0.6806,-0.9436, \
1.0000,0.3940,-0.6895,-0.9373,  1.0000,0.3883,-0.6984,-0.9308, \
1.0000,0.3827,-0.7071,-0.9239,  1.0000,0.3770,-0.7157,-0.9167, \
1.0000,0.3713,-0.7242,-0.9092,  1.0000,0.3656,-0.7327,-0.9013, \
1.0000,0.3599,-0.7410,-0.8932,  1.0000,0.3542,-0.7491,-0.8848, \
1.0000,0.3484,-0.7572,-0.8761,  1.0000,0.3427,-0.7652,-0.8670, \
1.0000,0.3369,-0.7730,-0.8577,  1.0000,0.3311,-0.7807,-0.8481, \
1.0000,0.3253,-0.7883,-0.8382,  1.0000,0.3195,-0.7958,-0.8280, \
1.0000,0.3137,-0.8032,-0.8176,  1.0000,0.3078,-0.8105,-0.8068, \
1.0000,0.3020,-0.8176,-0.7958,  1.0000,0.2962,-0.8246,-0.7846, \
1.0000,0.2903,-0.8315,-0.7730,  1.0000,0.2844,-0.8382,-0.7612, \
1.0000,0.2785,-0.8449,-0.7491,  1.0000,0.2726,-0.8514,-0.7368, \
1.0000,0.2667,-0.8577,-0.7242,  1.0000,0.2608,-0.8640,-0.7114, \
1.0000,0.2549,-0.8701,-0.6984,  1.0000,0.2489,-0.8761,-0.6851, \
1.0000,0.2430,-0.8819,-0.6716,  1.0000,0.2370,-0.8876,-0.6578, \
1.0000,0.2311,-0.8932,-0.6438,  1.0000,0.2251,-0.8987,-0.6296, \
1.0000,0.2191,-0.9040,-0.6152,  1.0000,0.2131,-0.9092,-0.6006, \
1.0000,0.2071,-0.9142,-0.5858,  1.0000,0.2011,-0.9191,-0.5708, \
1.0000,0.1951,-0.9239,-0.5556,  1.0000,0.1891,-0.9285,-0.5402, \
1.0000,0.1830,-0.9330,-0.5246,  1.0000,0.1770,-0.9373,-0.5088, \
1.0000,0.1710,-0.9415,-0.4929,  1.0000,0.1649,-0.9456,-0.4768, \
1.0000,0.1589,-0.9495,-0.4605,  1.0000,0.1528,-0.9533,-0.4441, \
1.0000,0.1467,-0.9569,-0.4276,  1.0000,0.1407,-0.9604,-0.4108, \
1.0000,0.1346,-0.9638,-0.3940,  1.0000,0.1285,-0.9670,-0.3770, \
1.0000,0.1224,-0.9700,-0.3599,  1.0000,0.1163,-0.9729,-0.3427, \
1.0000,0.1102,-0.9757,-0.3253,  1.0000,0.1041,-0.9783,-0.3078, \
1.0000,0.0980,-0.9808,-0.2903,  1.0000,0.0919,-0.9831,-0.2726, \
1.0000,0.0858,-0.9853,-0.2549,  1.0000,0.0797,-0.9873,-0.2370, \
1.0000,0.0736,-0.9892,-0.2191,  1.0000,0.0674,-0.9909,-0.2011, \
1.0000,0.0613,-0.9925,-0.1830,  1.0000,0.0552,-0.9939,-0.1649, \
1.0000,0.0491,-0.9952,-0.1467,  1.0000,0.0429,-0.9963,-0.1285, \
1.0000,0.0368,-0.9973,-0.1102,  1.0000,0.0307,-0.9981,-0.0919, \
1.0000,0.0245,-0.9988,-0.0736,  1.0000,0.0184,-0.9993,-0.0552, \
1.0000,0.0123,-0.9997,-0.0368,  1.0000,0.0061,-0.9999,-0.0184};
double FN1024_IMAG[1024] = {\
0.0000,0.0000,0.0000,0.0000,  0.0000,-0.0061,-0.0123,-0.0184, \
0.0000,-0.0123,-0.0245,-0.0368,  0.0000,-0.0184,-0.0368,-0.0552, \
0.0000,-0.0245,-0.0491,-0.0736,  0.0000,-0.0307,-0.0613,-0.0919, \
0.0000,-0.0368,-0.0736,-0.1102,  0.0000,-0.0429,-0.0858,-0.1285, \
0.0000,-0.0491,-0.0980,-0.1467,  0.0000,-0.0552,-0.1102,-0.1649, \
0.0000,-0.0613,-0.1224,-0.1830,  0.0000,-0.0674,-0.1346,-0.2011, \
0.0000,-0.0736,-0.1467,-0.2191,  0.0000,-0.0797,-0.1589,-0.2370, \
0.0000,-0.0858,-0.1710,-0.2549,  0.0000,-0.0919,-0.1830,-0.2726, \
0.0000,-0.0980,-0.1951,-0.2903,  -0.0000,-0.1041,-0.2071,-0.3078, \
-0.0000,-0.1102,-0.2191,-0.3253,  -0.0000,-0.1163,-0.2311,-0.3427, \
-0.0000,-0.1224,-0.2430,-0.3599,  -0.0000,-0.1285,-0.2549,-0.3770, \
-0.0000,-0.1346,-0.2667,-0.3940,  -0.0000,-0.1407,-0.2785,-0.4108, \
-0.0000,-0.1467,-0.2903,-0.4276,  -0.0000,-0.1528,-0.3020,-0.4441, \
-0.0000,-0.1589,-0.3137,-0.4605,  -0.0000,-0.1649,-0.3253,-0.4768, \
-0.0000,-0.1710,-0.3369,-0.4929,  -0.0000,-0.1770,-0.3484,-0.5088, \
-0.0000,-0.1830,-0.3599,-0.5246,  -0.0000,-0.1891,-0.3713,-0.5402, \
0.0000,-0.1951,-0.3827,-0.5556,  0.0000,-0.2011,-0.3940,-0.5708, \
0.0000,-0.2071,-0.4052,-0.5858,  0.0000,-0.2131,-0.4164,-0.6006, \
0.0000,-0.2191,-0.4276,-0.6152,  0.0000,-0.2251,-0.4386,-0.6296, \
0.0000,-0.2311,-0.4496,-0.6438,  0.0000,-0.2370,-0.4605,-0.6578, \
0.0000,-0.2430,-0.4714,-0.6716,  0.0000,-0.2489,-0.4822,-0.6851, \
0.0000,-0.2549,-0.4929,-0.6984,  0.0000,-0.2608,-0.5035,-0.7114, \
0.0000,-0.2667,-0.5141,-0.7242,  0.0000,-0.2726,-0.5246,-0.7368, \
0.0000,-0.2785,-0.5350,-0.7491,  0.0000,-0.2844,-0.5453,-0.7612, \
0.0000,-0.2903,-0.5556,-0.7730,  -0.0000,-0.2962,-0.5657,-0.7846, \
-0.0000,-0.3020,-0.5758,-0.7958,  -0.0000,-0.3078,-0.5858,-0.8068, \
-0.0000,-0.3137,-0.5957,-0.8176,  -0.0000,-0.3195,-0.6055,-0.8280, \
-0.0000,-0.3253,-0.6152,-0.8382,  -0.0000,-0.3311,-0.6249,-0.8481, \
-0.0000,-0.3369,-0.6344,-0.8577,  -0.0000,-0.3427,-0.6438,-0.8670, \
-0.0000,-0.3484,-0.6532,-0.8761,  -0.0000,-0.3542,-0.6624,-0.8848, \
-0.0000,-0.3599,-0.6716,-0.8932,  -0.0000,-0.3656,-0.6806,-0.9013, \
-0.0000,-0.3713,-0.6895,-0.9092,  -0.0000,-0.3770,-0.6984,-0.9167, \
0.0000,-0.3827,-0.7071,-0.9239,  0.0000,-0.3883,-0.7157,-0.9308, \
0.0000,-0.3940,-0.7242,-0.9373,  0.0000,-0.3996,-0.7327,-0.9436, \
0.0000,-0.4052,-0.7410,-0.9495,  0.0000,-0.4108,-0.7491,-0.9551, \
0.0000,-0.4164,-0.7572,-0.9604,  0.0000,-0.4220,-0.7652,-0.9654, \
0.0000,-0.4276,-0.7730,-0.9700,  0.0000,-0.4331,-0.7807,-0.9743, \
0.0000,-0.4386,-0.7883,-0.9783,  0.0000,-0.4441,-0.7958,-0.9820, \
0.0000,-0.4496,-0.8032,-0.9853,  0.0000,-0.4551,-0.8105,-0.9883, \
0.0000,-0.4605,-0.8176,-0.9909,  0.0000,-0.4660,-0.8246,-0.9932, \
0.0000,-0.4714,-0.8315,-0.9952,  -0.0000,-0.4768,-0.8382,-0.9968, \
-0.0000,-0.4822,-0.8449,-0.9981,  -0.0000,-0.4876,-0.8514,-0.9991, \
-0.0000,-0.4929,-0.8577,-0.9997,  -0.0000,-0.4982,-0.8640,-1.0000, \
-0.0000,-0.5035,-0.8701,-0.9999,  -0.0000,-0.5088,-0.8761,-0.9995, \
-0.0000,-0.5141,-0.8819,-0.9988,  -0.0000,-0.5194,-0.8876,-0.9977, \
-0.0000,-0.5246,-0.8932,-0.9963,  -0.0000,-0.5298,-0.8987,-0.9946, \
-0.0000,-0.5350,-0.9040,-0.9925,  -0.0000,-0.5402,-0.9092,-0.9901, \
-0.0000,-0.5453,-0.9142,-0.9873,  -0.0000,-0.5505,-0.9191,-0.9842, \
0.0000,-0.5556,-0.9239,-0.9808,  0.0000,-0.5607,-0.9285,-0.9770, \
0.0000,-0.5657,-0.9330,-0.9729,  0.0000,-0.5708,-0.9373,-0.9685, \
0.0000,-0.5758,-0.9415,-0.9638,  0.0000,-0.5808,-0.9456,-0.9587, \
0.0000,-0.5858,-0.9495,-0.9533,  0.0000,-0.5908,-0.9533,-0.9476, \
0.0000,-0.5957,-0.9569,-0.9415,  0.0000,-0.6006,-0.9604,-0.9352, \
0.0000,-0.6055,-0.9638,-0.9285,  0.0000,-0.6104,-0.9670,-0.9215, \
0.0000,-0.6152,-0.9700,-0.9142,  0.0000,-0.6201,-0.9729,-0.9066, \
0.0000,-0.6249,-0.9757,-0.8987,  0.0000,-0.6296,-0.9783,-0.8904, \
0.0000,-0.6344,-0.9808,-0.8819,  -0.0000,-0.6391,-0.9831,-0.8731, \
-0.0000,-0.6438,-0.9853,-0.8640,  -0.0000,-0.6485,-0.9873,-0.8546, \
-0.0000,-0.6532,-0.9892,-0.8449,  -0.0000,-0.6578,-0.9909,-0.8349, \
-0.0000,-0.6624,-0.9925,-0.8246,  -0.0000,-0.6670,-0.9939,-0.8140, \
-0.0000,-0.6716,-0.9952,-0.8032,  -0.0000,-0.6761,-0.9963,-0.7921, \
-0.0000,-0.6806,-0.9973,-0.7807,  -0.0000,-0.6851,-0.9981,-0.7691, \
-0.0000,-0.6895,-0.9988,-0.7572,  -0.0000,-0.6940,-0.9993,-0.7451, \
-0.0000,-0.6984,-0.9997,-0.7327,  -0.0000,-0.7028,-0.9999,-0.7200, \
0.0000,-0.7071,-1.0000,-0.7071,  0.0000,-0.7114,-0.9999,-0.6940, \
0.0000,-0.7157,-0.9997,-0.6806,  0.0000,-0.7200,-0.9993,-0.6670, \
0.0000,-0.7242,-0.9988,-0.6532,  0.0000,-0.7285,-0.9981,-0.6391, \
0.0000,-0.7327,-0.9973,-0.6249,  0.0000,-0.7368,-0.9963,-0.6104, \
0.0000,-0.7410,-0.9952,-0.5957,  0.0000,-0.7451,-0.9939,-0.5808, \
0.0000,-0.7491,-0.9925,-0.5657,  0.0000,-0.7532,-0.9909,-0.5505, \
0.0000,-0.7572,-0.9892,-0.5350,  0.0000,-0.7612,-0.9873,-0.5194, \
0.0000,-0.7652,-0.9853,-0.5035,  0.0000,-0.7691,-0.9831,-0.4876, \
0.0000,-0.7730,-0.9808,-0.4714,  -0.0000,-0.7769,-0.9783,-0.4551, \
-0.0000,-0.7807,-0.9757,-0.4386,  -0.0000,-0.7846,-0.9729,-0.4220, \
-0.0000,-0.7883,-0.9700,-0.4052,  -0.0000,-0.7921,-0.9670,-0.3883, \
-0.0000,-0.7958,-0.9638,-0.3713,  -0.0000,-0.7995,-0.9604,-0.3542, \
-0.0000,-0.8032,-0.9569,-0.3369,  -0.0000,-0.8068,-0.9533,-0.3195, \
-0.0000,-0.8105,-0.9495,-0.3020,  -0.0000,-0.8140,-0.9456,-0.2844, \
-0.0000,-0.8176,-0.9415,-0.2667,  -0.0000,-0.8211,-0.9373,-0.2489, \
-0.0000,-0.8246,-0.9330,-0.2311,  -0.0000,-0.8280,-0.9285,-0.2131, \
0.0000,-0.8315,-0.9239,-0.1951,  0.0000,-0.8349,-0.9191,-0.1770, \
0.0000,-0.8382,-0.9142,-0.1589,  0.0000,-0.8416,-0.9092,-0.1407, \
0.0000,-0.8449,-0.9040,-0.1224,  0.0000,-0.8481,-0.8987,-0.1041, \
0.0000,-0.8514,-0.8932,-0.0858,  0.0000,-0.8546,-0.8876,-0.0674, \
0.0000,-0.8577,-0.8819,-0.0491,  0.0000,-0.8609,-0.8761,-0.0307, \
0.0000,-0.8640,-0.8701,-0.0123,  0.0000,-0.8670,-0.8640,0.0061, \
0.0000,-0.8701,-0.8577,0.0245,  0.0000,-0.8731,-0.8514,0.0429, \
0.0000,-0.8761,-0.8449,0.0613,  0.0000,-0.8790,-0.8382,0.0797, \
-0.0000,-0.8819,-0.8315,0.0980,  -0.0000,-0.8848,-0.8246,0.1163, \
-0.0000,-0.8876,-0.8176,0.1346,  -0.0000,-0.8904,-0.8105,0.1528, \
-0.0000,-0.8932,-0.8032,0.1710,  -0.0000,-0.8960,-0.7958,0.1891, \
-0.0000,-0.8987,-0.7883,0.2071,  -0.0000,-0.9013,-0.7807,0.2251, \
-0.0000,-0.9040,-0.7730,0.2430,  -0.0000,-0.9066,-0.7652,0.2608, \
-0.0000,-0.9092,-0.7572,0.2785,  -0.0000,-0.9117,-0.7491,0.2962, \
-0.0000,-0.9142,-0.7410,0.3137,  -0.0000,-0.9167,-0.7327,0.3311, \
-0.0000,-0.9191,-0.7242,0.3484,  -0.0000,-0.9215,-0.7157,0.3656, \
0.0000,-0.9239,-0.7071,0.3827,  0.0000,-0.9262,-0.6984,0.3996, \
0.0000,-0.9285,-0.6895,0.4164,  0.0000,-0.9308,-0.6806,0.4331, \
0.0000,-0.9330,-0.6716,0.4496,  0.0000,-0.9352,-0.6624,0.4660, \
0.0000,-0.9373,-0.6532,0.4822,  0.0000,-0.9395,-0.6438,0.4982, \
0.0000,-0.9415,-0.6344,0.5141,  0.0000,-0.9436,-0.6249,0.5298, \
0.0000,-0.9456,-0.6152,0.5453,  0.0000,-0.9476,-0.6055,0.5607, \
0.0000,-0.9495,-0.5957,0.5758,  0.0000,-0.9514,-0.5858,0.5908, \
0.0000,-0.9533,-0.5758,0.6055,  0.0000,-0.9551,-0.5657,0.6201, \
0.0000,-0.9569,-0.5556,0.6344,  -0.0000,-0.9587,-0.5453,0.6485, \
-0.0000,-0.9604,-0.5350,0.6624,  -0.0000,-0.9621,-0.5246,0.6761, \
-0.0000,-0.9638,-0.5141,0.6895,  -0.0000,-0.9654,-0.5035,0.7028, \
-0.0000,-0.9670,-0.4929,0.7157,  -0.0000,-0.9685,-0.4822,0.7285, \
-0.0000,-0.9700,-0.4714,0.7410,  -0.0000,-0.9715,-0.4605,0.7532, \
-0.0000,-0.9729,-0.4496,0.7652,  -0.0000,-0.9743,-0.4386,0.7769, \
-0.0000,-0.9757,-0.4276,0.7883,  -0.0000,-0.9770,-0.4164,0.7995, \
-0.0000,-0.9783,-0.4052,0.8105,  -0.0000,-0.9796,-0.3940,0.8211, \
0.0000,-0.9808,-0.3827,0.8315,  0.0000,-0.9820,-0.3713,0.8416, \
0.0000,-0.9831,-0.3599,0.8514,  0.0000,-0.9842,-0.3484,0.8609, \
0.0000,-0.9853,-0.3369,0.8701,  0.0000,-0.9863,-0.3253,0.8790, \
0.0000,-0.9873,-0.3137,0.8876,  0.0000,-0.9883,-0.3020,0.8960, \
0.0000,-0.9892,-0.2903,0.9040,  0.0000,-0.9901,-0.2785,0.9117, \
0.0000,-0.9909,-0.2667,0.9191,  0.0000,-0.9917,-0.2549,0.9262, \
0.0000,-0.9925,-0.2430,0.9330,  0.0000,-0.9932,-0.2311,0.9395, \
0.0000,-0.9939,-0.2191,0.9456,  0.0000,-0.9946,-0.2071,0.9514, \
0.0000,-0.9952,-0.1951,0.9569,  -0.0000,-0.9958,-0.1830,0.9621, \
-0.0000,-0.9963,-0.1710,0.9670,  -0.0000,-0.9968,-0.1589,0.9715, \
-0.0000,-0.9973,-0.1467,0.9757,  -0.0000,-0.9977,-0.1346,0.9796, \
-0.0000,-0.9981,-0.1224,0.9831,  -0.0000,-0.9985,-0.1102,0.9863, \
-0.0000,-0.9988,-0.0980,0.9892,  -0.0000,-0.9991,-0.0858,0.9917, \
-0.0000,-0.9993,-0.0736,0.9939,  -0.0000,-0.9995,-0.0613,0.9958, \
-0.0000,-0.9997,-0.0491,0.9973,  -0.0000,-0.9998,-0.0368,0.9985, \
-0.0000,-0.9999,-0.0245,0.9993,  -0.0000,-1.0000,-0.0123,0.9998};
