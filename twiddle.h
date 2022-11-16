#include "../tmp/sfp/lib/sfp.hh"
     
double FN1024_REAL[1024] = { \
1.000000,1.000000,1.000000,1.000000,  1.000000,0.999981,0.999925,0.999831, \
1.000000,0.999925,0.999699,0.999322,  1.000000,0.999831,0.999322,0.998476, \
1.000000,0.999699,0.998795,0.997290,  1.000000,0.999529,0.998118,0.995767, \
1.000000,0.999322,0.997290,0.993907,  1.000000,0.999078,0.996313,0.991710, \
1.000000,0.998795,0.995185,0.989177,  1.000000,0.998476,0.993907,0.986308, \
1.000000,0.998118,0.992480,0.983105,  1.000000,0.997723,0.990903,0.979570, \
1.000000,0.997290,0.989177,0.975702,  1.000000,0.996820,0.987301,0.971504, \
1.000000,0.996313,0.985278,0.966976,  1.000000,0.995767,0.983105,0.962121, \
1.000000,0.995185,0.980785,0.956940,  1.000000,0.994565,0.978317,0.951435, \
1.000000,0.993907,0.975702,0.945607,  1.000000,0.993212,0.972940,0.939459, \
1.000000,0.992480,0.970031,0.932993,  1.000000,0.991710,0.966976,0.926210, \
1.000000,0.990903,0.963776,0.919114,  1.000000,0.990058,0.960431,0.911706, \
1.000000,0.989177,0.956940,0.903989,  1.000000,0.988258,0.953306,0.895966, \
1.000000,0.987301,0.949528,0.887640,  1.000000,0.986308,0.945607,0.879012, \
1.000000,0.985278,0.941544,0.870087,  1.000000,0.984210,0.937339,0.860867, \
1.000000,0.983105,0.932993,0.851355,  1.000000,0.981964,0.928506,0.841555, \
1.000000,0.980785,0.923880,0.831470,  1.000000,0.979570,0.919114,0.821103, \
1.000000,0.978317,0.914210,0.810457,  1.000000,0.977028,0.909168,0.799537, \
1.000000,0.975702,0.903989,0.788346,  1.000000,0.974339,0.898674,0.776888, \
1.000000,0.972940,0.893224,0.765167,  1.000000,0.971504,0.887640,0.753187, \
1.000000,0.970031,0.881921,0.740951,  1.000000,0.968522,0.876070,0.728464, \
1.000000,0.966976,0.870087,0.715731,  1.000000,0.965394,0.863973,0.702755, \
1.000000,0.963776,0.857729,0.689541,  1.000000,0.962121,0.851355,0.676093, \
1.000000,0.960431,0.844854,0.662416,  1.000000,0.958703,0.838225,0.648514, \
1.000000,0.956940,0.831470,0.634393,  1.000000,0.955141,0.824589,0.620057, \
1.000000,0.953306,0.817585,0.605511,  1.000000,0.951435,0.810457,0.590760, \
1.000000,0.949528,0.803208,0.575808,  1.000000,0.947586,0.795837,0.560662, \
1.000000,0.945607,0.788346,0.545325,  1.000000,0.943593,0.780737,0.529804, \
1.000000,0.941544,0.773010,0.514103,  1.000000,0.939459,0.765167,0.498228, \
1.000000,0.937339,0.757209,0.482184,  1.000000,0.935184,0.749136,0.465976, \
1.000000,0.932993,0.740951,0.449611,  1.000000,0.930767,0.732654,0.433094, \
1.000000,0.928506,0.724247,0.416430,  1.000000,0.926210,0.715731,0.399624, \
1.000000,0.923880,0.707107,0.382683,  1.000000,0.921514,0.698376,0.365613, \
1.000000,0.919114,0.689541,0.348419,  1.000000,0.916679,0.680601,0.331106, \
1.000000,0.914210,0.671559,0.313682,  1.000000,0.911706,0.662416,0.296151, \
1.000000,0.909168,0.653173,0.278520,  1.000000,0.906596,0.643832,0.260794, \
1.000000,0.903989,0.634393,0.242980,  1.000000,0.901349,0.624859,0.225084, \
1.000000,0.898674,0.615232,0.207111,  1.000000,0.895966,0.605511,0.189069, \
1.000000,0.893224,0.595699,0.170962,  1.000000,0.890449,0.585798,0.152797, \
1.000000,0.887640,0.575808,0.134581,  1.000000,0.884797,0.565732,0.116319, \
1.000000,0.881921,0.555570,0.098017,  1.000000,0.879012,0.545325,0.079682, \
1.000000,0.876070,0.534998,0.061321,  1.000000,0.873095,0.524590,0.042938, \
1.000000,0.870087,0.514103,0.024541,  1.000000,0.867046,0.503538,0.006136, \
1.000000,0.863973,0.492898,-0.012272,  1.000000,0.860867,0.482184,-0.030675, \
1.000000,0.857729,0.471397,-0.049068,  1.000000,0.854558,0.460539,-0.067444, \
1.000000,0.851355,0.449611,-0.085797,  1.000000,0.848120,0.438616,-0.104122, \
1.000000,0.844854,0.427555,-0.122411,  1.000000,0.841555,0.416430,-0.140658, \
1.000000,0.838225,0.405241,-0.158858,  1.000000,0.834863,0.393992,-0.177004, \
1.000000,0.831470,0.382683,-0.195090,  1.000000,0.828045,0.371317,-0.213110, \
1.000000,0.824589,0.359895,-0.231058,  1.000000,0.821103,0.348419,-0.248928, \
1.000000,0.817585,0.336890,-0.266713,  1.000000,0.814036,0.325310,-0.284408, \
1.000000,0.810457,0.313682,-0.302006,  1.000000,0.806848,0.302006,-0.319502, \
1.000000,0.803208,0.290285,-0.336890,  1.000000,0.799537,0.278520,-0.354164, \
1.000000,0.795837,0.266713,-0.371317,  1.000000,0.792107,0.254866,-0.388345, \
1.000000,0.788346,0.242980,-0.405241,  1.000000,0.784557,0.231058,-0.422000, \
1.000000,0.780737,0.219101,-0.438616,  1.000000,0.776888,0.207111,-0.455084, \
1.000000,0.773010,0.195090,-0.471397,  1.000000,0.769103,0.183040,-0.487550, \
1.000000,0.765167,0.170962,-0.503538,  1.000000,0.761202,0.158858,-0.519356, \
1.000000,0.757209,0.146730,-0.534998,  1.000000,0.753187,0.134581,-0.550458, \
1.000000,0.749136,0.122411,-0.565732,  1.000000,0.745058,0.110222,-0.580814, \
1.000000,0.740951,0.098017,-0.595699,  1.000000,0.736817,0.085797,-0.610383, \
1.000000,0.732654,0.073565,-0.624859,  1.000000,0.728464,0.061321,-0.639124, \
1.000000,0.724247,0.049068,-0.653173,  1.000000,0.720003,0.036807,-0.667000, \
1.000000,0.715731,0.024541,-0.680601,  1.000000,0.711432,0.012272,-0.693971, \
1.000000,0.689541,-0.049068,-0.757209,  1.000000,0.685084,-0.061321,-0.769103, \
1.000000,0.680601,-0.073565,-0.780737,  1.000000,0.676093,-0.085797,-0.792107, \
1.000000,0.671559,-0.098017,-0.803208,  1.000000,0.667000,-0.110222,-0.814036, \
1.000000,0.662416,-0.122411,-0.824589,  1.000000,0.657807,-0.134581,-0.834863, \
1.000000,0.653173,-0.146730,-0.844854,  1.000000,0.648514,-0.158858,-0.854558, \
1.000000,0.643832,-0.170962,-0.863973,  1.000000,0.639124,-0.183040,-0.873095, \
1.000000,0.634393,-0.195090,-0.881921,  1.000000,0.629638,-0.207111,-0.890449, \
1.000000,0.624859,-0.219101,-0.898674,  1.000000,0.620057,-0.231058,-0.906596, \
1.000000,0.615232,-0.242980,-0.914210,  1.000000,0.610383,-0.254866,-0.921514, \
1.000000,0.605511,-0.266713,-0.928506,  1.000000,0.600616,-0.278520,-0.935184, \
1.000000,0.595699,-0.290285,-0.941544,  1.000000,0.590760,-0.302006,-0.947586, \
1.000000,0.585798,-0.313682,-0.953306,  1.000000,0.580814,-0.325310,-0.958703, \
1.000000,0.575808,-0.336890,-0.963776,  1.000000,0.570781,-0.348419,-0.968522, \
1.000000,0.565732,-0.359895,-0.972940,  1.000000,0.560662,-0.371317,-0.977028, \
1.000000,0.555570,-0.382683,-0.980785,  1.000000,0.550458,-0.393992,-0.984210, \
1.000000,0.545325,-0.405241,-0.987301,  1.000000,0.540171,-0.416430,-0.990058, \
1.000000,0.534998,-0.427555,-0.992480,  1.000000,0.529804,-0.438616,-0.994565, \
1.000000,0.524590,-0.449611,-0.996313,  1.000000,0.519356,-0.460539,-0.997723, \
1.000000,0.514103,-0.471397,-0.998795,  1.000000,0.508830,-0.482184,-0.999529, \
1.000000,0.503538,-0.492898,-0.999925,  1.000000,0.498228,-0.503538,-0.999981, \
1.000000,0.492898,-0.514103,-0.999699,  1.000000,0.487550,-0.524590,-0.999078, \
1.000000,0.482184,-0.534998,-0.998118,  1.000000,0.476799,-0.545325,-0.996820, \
1.000000,0.471397,-0.555570,-0.995185,  1.000000,0.465976,-0.565732,-0.993212, \
1.000000,0.460539,-0.575808,-0.990903,  1.000000,0.455084,-0.585798,-0.988258, \
1.000000,0.449611,-0.595699,-0.985278,  1.000000,0.444122,-0.605511,-0.981964, \
1.000000,0.438616,-0.615232,-0.978317,  1.000000,0.433094,-0.624859,-0.974339, \
1.000000,0.427555,-0.634393,-0.970031,  1.000000,0.422000,-0.643832,-0.965394, \
1.000000,0.416430,-0.653173,-0.960431,  1.000000,0.410843,-0.662416,-0.955141, \
1.000000,0.405241,-0.671559,-0.949528,  1.000000,0.399624,-0.680601,-0.943593, \
1.000000,0.393992,-0.689541,-0.937339,  1.000000,0.388345,-0.698376,-0.930767, \
1.000000,0.382683,-0.707107,-0.923880,  1.000000,0.377007,-0.715731,-0.916679, \
1.000000,0.371317,-0.724247,-0.909168,  1.000000,0.365613,-0.732654,-0.901349, \
1.000000,0.359895,-0.740951,-0.893224,  1.000000,0.354164,-0.749136,-0.884797, \
1.000000,0.348419,-0.757209,-0.876070,  1.000000,0.342661,-0.765167,-0.867046, \
1.000000,0.336890,-0.773010,-0.857729,  1.000000,0.331106,-0.780737,-0.848120, \
1.000000,0.325310,-0.788346,-0.838225,  1.000000,0.319502,-0.795837,-0.828045, \
1.000000,0.313682,-0.803208,-0.817585,  1.000000,0.307850,-0.810457,-0.806848, \
1.000000,0.302006,-0.817585,-0.795837,  1.000000,0.296151,-0.824589,-0.784557, \
1.000000,0.290285,-0.831470,-0.773010,  1.000000,0.284408,-0.838225,-0.761202, \
1.000000,0.278520,-0.844854,-0.749136,  1.000000,0.272621,-0.851355,-0.736817, \
1.000000,0.266713,-0.857729,-0.724247,  1.000000,0.260794,-0.863973,-0.711432, \
1.000000,0.254866,-0.870087,-0.698376,  1.000000,0.248928,-0.876070,-0.685084, \
1.000000,0.242980,-0.881921,-0.671559,  1.000000,0.237024,-0.887640,-0.657807, \
1.000000,0.231058,-0.893224,-0.643832,  1.000000,0.225084,-0.898674,-0.629638, \
1.000000,0.219101,-0.903989,-0.615232,  1.000000,0.213110,-0.909168,-0.600616, \
1.000000,0.207111,-0.914210,-0.585798,  1.000000,0.201105,-0.919114,-0.570781, \
1.000000,0.195090,-0.923880,-0.555570,  1.000000,0.189069,-0.928506,-0.540171, \
1.000000,0.183040,-0.932993,-0.524590,  1.000000,0.177004,-0.937339,-0.508830, \
1.000000,0.170962,-0.941544,-0.492898,  1.000000,0.164913,-0.945607,-0.476799, \
1.000000,0.158858,-0.949528,-0.460539,  1.000000,0.152797,-0.953306,-0.444122, \
1.000000,0.146730,-0.956940,-0.427555,  1.000000,0.140658,-0.960431,-0.410843, \
1.000000,0.134581,-0.963776,-0.393992,  1.000000,0.128498,-0.966976,-0.377007, \
1.000000,0.122411,-0.970031,-0.359895,  1.000000,0.116319,-0.972940,-0.342661, \
1.000000,0.110222,-0.975702,-0.325310,  1.000000,0.104122,-0.978317,-0.307850, \
1.000000,0.098017,-0.980785,-0.290285,  1.000000,0.091909,-0.983105,-0.272621, \
1.000000,0.085797,-0.985278,-0.254866,  1.000000,0.079682,-0.987301,-0.237024, \
1.000000,0.073565,-0.989177,-0.219101,  1.000000,0.067444,-0.990903,-0.201105, \
1.000000,0.061321,-0.992480,-0.183040,  1.000000,0.055195,-0.993907,-0.164913, \
1.000000,0.049068,-0.995185,-0.146730,  1.000000,0.042938,-0.996313,-0.128498, \
1.000000,0.036807,-0.997290,-0.110222,  1.000000,0.030675,-0.998118,-0.091909, \
1.000000,0.024541,-0.998795,-0.073565,  1.000000,0.018407,-0.999322,-0.055195, \
1.000000,0.012272,-0.999699,-0.036807,  1.000000,0.006136,-0.999925,-0.018407  \
};
double FN1024_IMAG[1024] = { \
0.000000,0.000000,0.000000,0.000000,  0.000000,-0.006136,-0.012272,-0.018407, \
0.000000,-0.012272,-0.024541,-0.036807,  0.000000,-0.018407,-0.036807,-0.055195, \
0.000000,-0.024541,-0.049068,-0.073565,  0.000000,-0.030675,-0.061321,-0.091909, \
0.000000,-0.036807,-0.073565,-0.110222,  0.000000,-0.042938,-0.085797,-0.128498, \
0.000000,-0.049068,-0.098017,-0.146730,  0.000000,-0.055195,-0.110222,-0.164913, \
0.000000,-0.061321,-0.122411,-0.183040,  0.000000,-0.067444,-0.134581,-0.201105, \
0.000000,-0.073565,-0.146730,-0.219101,  0.000000,-0.079682,-0.158858,-0.237024, \
0.000000,-0.085797,-0.170962,-0.254866,  0.000000,-0.091909,-0.183040,-0.272621, \
0.000000,-0.098017,-0.195090,-0.290285,  -0.000000,-0.104122,-0.207111,-0.307850, \
-0.000000,-0.110222,-0.219101,-0.325310,  -0.000000,-0.116319,-0.231058,-0.342661, \
-0.000000,-0.122411,-0.242980,-0.359895,  -0.000000,-0.128498,-0.254866,-0.377007, \
-0.000000,-0.134581,-0.266713,-0.393992,  -0.000000,-0.140658,-0.278520,-0.410843, \
-0.000000,-0.146730,-0.290285,-0.427555,  -0.000000,-0.152797,-0.302006,-0.444122, \
-0.000000,-0.158858,-0.313682,-0.460539,  -0.000000,-0.164913,-0.325310,-0.476799, \
-0.000000,-0.170962,-0.336890,-0.492898,  -0.000000,-0.177004,-0.348419,-0.508830, \
-0.000000,-0.183040,-0.359895,-0.524590,  -0.000000,-0.189069,-0.371317,-0.540171, \
0.000000,-0.195090,-0.382683,-0.555570,  0.000000,-0.201105,-0.393992,-0.570781, \
0.000000,-0.207111,-0.405241,-0.585798,  0.000000,-0.213110,-0.416430,-0.600616, \
0.000000,-0.219101,-0.427555,-0.615232,  0.000000,-0.225084,-0.438616,-0.629638, \
0.000000,-0.231058,-0.449611,-0.643832,  0.000000,-0.237024,-0.460539,-0.657807, \
0.000000,-0.242980,-0.471397,-0.671559,  0.000000,-0.248928,-0.482184,-0.685084, \
0.000000,-0.254866,-0.492898,-0.698376,  0.000000,-0.260794,-0.503538,-0.711432, \
0.000000,-0.266713,-0.514103,-0.724247,  0.000000,-0.272621,-0.524590,-0.736817, \
0.000000,-0.278520,-0.534998,-0.749136,  0.000000,-0.284408,-0.545325,-0.761202, \
0.000000,-0.290285,-0.555570,-0.773010,  -0.000000,-0.296151,-0.565732,-0.784557, \
-0.000000,-0.302006,-0.575808,-0.795837,  -0.000000,-0.307850,-0.585798,-0.806848, \
-0.000000,-0.313682,-0.595699,-0.817585,  -0.000000,-0.319502,-0.605511,-0.828045, \
-0.000000,-0.325310,-0.615232,-0.838225,  -0.000000,-0.331106,-0.624859,-0.848120, \
-0.000000,-0.336890,-0.634393,-0.857729,  -0.000000,-0.342661,-0.643832,-0.867046, \
-0.000000,-0.348419,-0.653173,-0.876070,  -0.000000,-0.354164,-0.662416,-0.884797, \
-0.000000,-0.359895,-0.671559,-0.893224,  -0.000000,-0.365613,-0.680601,-0.901349, \
-0.000000,-0.371317,-0.689541,-0.909168,  -0.000000,-0.377007,-0.698376,-0.916679, \
0.000000,-0.382683,-0.707107,-0.923880,  0.000000,-0.388345,-0.715731,-0.930767, \
0.000000,-0.393992,-0.724247,-0.937339,  0.000000,-0.399624,-0.732654,-0.943593, \
0.000000,-0.405241,-0.740951,-0.949528,  0.000000,-0.410843,-0.749136,-0.955141, \
0.000000,-0.416430,-0.757209,-0.960431,  0.000000,-0.422000,-0.765167,-0.965394, \
0.000000,-0.427555,-0.773010,-0.970031,  0.000000,-0.433094,-0.780737,-0.974339, \
0.000000,-0.438616,-0.788346,-0.978317,  0.000000,-0.444122,-0.795837,-0.981964, \
0.000000,-0.449611,-0.803208,-0.985278,  0.000000,-0.455084,-0.810457,-0.988258, \
0.000000,-0.460539,-0.817585,-0.990903,  0.000000,-0.465976,-0.824589,-0.993212, \
0.000000,-0.471397,-0.831470,-0.995185,  -0.000000,-0.476799,-0.838225,-0.996820, \
-0.000000,-0.482184,-0.844854,-0.998118,  -0.000000,-0.487550,-0.851355,-0.999078, \
-0.000000,-0.492898,-0.857729,-0.999699,  -0.000000,-0.498228,-0.863973,-0.999981, \
-0.000000,-0.503538,-0.870087,-0.999925,  -0.000000,-0.508830,-0.876070,-0.999529, \
-0.000000,-0.514103,-0.881921,-0.998795,  -0.000000,-0.519356,-0.887640,-0.997723, \
-0.000000,-0.524590,-0.893224,-0.996313,  -0.000000,-0.529804,-0.898674,-0.994565, \
-0.000000,-0.534998,-0.903989,-0.992480,  -0.000000,-0.540171,-0.909168,-0.990058, \
-0.000000,-0.545325,-0.914210,-0.987301,  -0.000000,-0.550458,-0.919114,-0.984210, \
0.000000,-0.555570,-0.923880,-0.980785,  0.000000,-0.560662,-0.928506,-0.977028, \
0.000000,-0.565732,-0.932993,-0.972940,  0.000000,-0.570781,-0.937339,-0.968522, \
0.000000,-0.575808,-0.941544,-0.963776,  0.000000,-0.580814,-0.945607,-0.958703, \
0.000000,-0.585798,-0.949528,-0.953306,  0.000000,-0.590760,-0.953306,-0.947586, \
0.000000,-0.595699,-0.956940,-0.941544,  0.000000,-0.600616,-0.960431,-0.935184, \
0.000000,-0.605511,-0.963776,-0.928506,  0.000000,-0.610383,-0.966976,-0.921514, \
0.000000,-0.615232,-0.970031,-0.914210,  0.000000,-0.620057,-0.972940,-0.906596, \
0.000000,-0.624859,-0.975702,-0.898674,  0.000000,-0.629638,-0.978317,-0.890449, \
0.000000,-0.634393,-0.980785,-0.881921,  -0.000000,-0.639124,-0.983105,-0.873095, \
-0.000000,-0.643832,-0.985278,-0.863973,  -0.000000,-0.648514,-0.987301,-0.854558, \
-0.000000,-0.653173,-0.989177,-0.844854,  -0.000000,-0.657807,-0.990903,-0.834863, \
-0.000000,-0.662416,-0.992480,-0.824589,  -0.000000,-0.667000,-0.993907,-0.814036, \
-0.000000,-0.671559,-0.995185,-0.803208,  -0.000000,-0.676093,-0.996313,-0.792107, \
-0.000000,-0.680601,-0.997290,-0.780737,  -0.000000,-0.685084,-0.998118,-0.769103, \
-0.000000,-0.689541,-0.998795,-0.757209,  -0.000000,-0.693971,-0.999322,-0.745058, \
-0.000000,-0.698376,-0.999699,-0.732654,  -0.000000,-0.702755,-0.999925,-0.720003, \
0.000000,-0.707107,-1.000000,-0.707107,  0.000000,-0.711432,-0.999925,-0.693971, \
0.000000,-0.715731,-0.999699,-0.680601,  0.000000,-0.720003,-0.999322,-0.667000, \
0.000000,-0.724247,-0.998795,-0.653173,  0.000000,-0.728464,-0.998118,-0.639124, \
0.000000,-0.732654,-0.997290,-0.624859,  0.000000,-0.736817,-0.996313,-0.610383, \
0.000000,-0.740951,-0.995185,-0.595699,  0.000000,-0.745058,-0.993907,-0.580814, \
0.000000,-0.749136,-0.992480,-0.565732,  0.000000,-0.753187,-0.990903,-0.550458, \
0.000000,-0.757209,-0.989177,-0.534998,  0.000000,-0.761202,-0.987301,-0.519356, \
0.000000,-0.765167,-0.985278,-0.503538,  0.000000,-0.769103,-0.983105,-0.487550, \
0.000000,-0.773010,-0.980785,-0.471397,  -0.000000,-0.776888,-0.978317,-0.455084, \
-0.000000,-0.780737,-0.975702,-0.438616,  -0.000000,-0.784557,-0.972940,-0.422000, \
-0.000000,-0.788346,-0.970031,-0.405241,  -0.000000,-0.792107,-0.966976,-0.388345, \
-0.000000,-0.795837,-0.963776,-0.371317,  -0.000000,-0.799537,-0.960431,-0.354164, \
-0.000000,-0.803208,-0.956940,-0.336890,  -0.000000,-0.806848,-0.953306,-0.319502, \
-0.000000,-0.810457,-0.949528,-0.302006,  -0.000000,-0.814036,-0.945607,-0.284408, \
-0.000000,-0.817585,-0.941544,-0.266713,  -0.000000,-0.821103,-0.937339,-0.248928, \
-0.000000,-0.824589,-0.932993,-0.231058,  -0.000000,-0.828045,-0.928506,-0.213110, \
0.000000,-0.831470,-0.923880,-0.195090,  0.000000,-0.834863,-0.919114,-0.177004, \
0.000000,-0.838225,-0.914210,-0.158858,  0.000000,-0.841555,-0.909168,-0.140658, \
0.000000,-0.844854,-0.903989,-0.122411,  0.000000,-0.848120,-0.898674,-0.104122, \
0.000000,-0.851355,-0.893224,-0.085797,  0.000000,-0.854558,-0.887640,-0.067444, \
0.000000,-0.857729,-0.881921,-0.049068,  0.000000,-0.860867,-0.876070,-0.030675, \
0.000000,-0.863973,-0.870087,-0.012272,  0.000000,-0.867046,-0.863973,0.006136, \
0.000000,-0.870087,-0.857729,0.024541,  0.000000,-0.873095,-0.851355,0.042938, \
0.000000,-0.876070,-0.844854,0.061321,  0.000000,-0.879012,-0.838225,0.079682, \
-0.000000,-0.881921,-0.831470,0.098017,  -0.000000,-0.884797,-0.824589,0.116319, \
-0.000000,-0.887640,-0.817585,0.134581,  -0.000000,-0.890449,-0.810457,0.152797, \
-0.000000,-0.893224,-0.803208,0.170962,  -0.000000,-0.895966,-0.795837,0.189069, \
-0.000000,-0.898674,-0.788346,0.207111,  -0.000000,-0.901349,-0.780737,0.225084, \
-0.000000,-0.903989,-0.773010,0.242980,  -0.000000,-0.906596,-0.765167,0.260794, \
-0.000000,-0.909168,-0.757209,0.278520,  -0.000000,-0.911706,-0.749136,0.296151, \
-0.000000,-0.914210,-0.740951,0.313682,  -0.000000,-0.916679,-0.732654,0.331106, \
-0.000000,-0.919114,-0.724247,0.348419,  -0.000000,-0.921514,-0.715731,0.365613, \
0.000000,-0.923880,-0.707107,0.382683,  0.000000,-0.926210,-0.698376,0.399624, \
0.000000,-0.928506,-0.689541,0.416430,  0.000000,-0.930767,-0.680601,0.433094, \
0.000000,-0.932993,-0.671559,0.449611,  0.000000,-0.935184,-0.662416,0.465976, \
0.000000,-0.937339,-0.653173,0.482184,  0.000000,-0.939459,-0.643832,0.498228, \
0.000000,-0.941544,-0.634393,0.514103,  0.000000,-0.943593,-0.624859,0.529804, \
0.000000,-0.945607,-0.615232,0.545325,  0.000000,-0.947586,-0.605511,0.560662, \
0.000000,-0.949528,-0.595699,0.575808,  0.000000,-0.951435,-0.585798,0.590760, \
0.000000,-0.953306,-0.575808,0.605511,  0.000000,-0.955141,-0.565732,0.620057, \
0.000000,-0.956940,-0.555570,0.634393,  -0.000000,-0.958703,-0.545325,0.648514, \
-0.000000,-0.960431,-0.534998,0.662416,  -0.000000,-0.962121,-0.524590,0.676093, \
-0.000000,-0.963776,-0.514103,0.689541,  -0.000000,-0.965394,-0.503538,0.702755, \
-0.000000,-0.966976,-0.492898,0.715731,  -0.000000,-0.968522,-0.482184,0.728464, \
-0.000000,-0.970031,-0.471397,0.740951,  -0.000000,-0.971504,-0.460539,0.753187, \
-0.000000,-0.972940,-0.449611,0.765167,  -0.000000,-0.974339,-0.438616,0.776888, \
-0.000000,-0.975702,-0.427555,0.788346,  -0.000000,-0.977028,-0.416430,0.799537, \
-0.000000,-0.978317,-0.405241,0.810457,  -0.000000,-0.979570,-0.393992,0.821103, \
0.000000,-0.980785,-0.382683,0.831470,  0.000000,-0.981964,-0.371317,0.841555, \
0.000000,-0.983105,-0.359895,0.851355,  0.000000,-0.984210,-0.348419,0.860867, \
0.000000,-0.985278,-0.336890,0.870087,  0.000000,-0.986308,-0.325310,0.879012, \
0.000000,-0.987301,-0.313682,0.887640,  0.000000,-0.988258,-0.302006,0.895966, \
0.000000,-0.989177,-0.290285,0.903989,  0.000000,-0.990058,-0.278520,0.911706, \
0.000000,-0.990903,-0.266713,0.919114,  0.000000,-0.991710,-0.254866,0.926210, \
0.000000,-0.992480,-0.242980,0.932993,  0.000000,-0.993212,-0.231058,0.939459, \
0.000000,-0.993907,-0.219101,0.945607,  0.000000,-0.994565,-0.207111,0.951435, \
0.000000,-0.995185,-0.195090,0.956940,  -0.000000,-0.995767,-0.183040,0.962121, \
-0.000000,-0.996313,-0.170962,0.966976,  -0.000000,-0.996820,-0.158858,0.971504, \
-0.000000,-0.997290,-0.146730,0.975702,  -0.000000,-0.997723,-0.134581,0.979570, \
-0.000000,-0.998118,-0.122411,0.983105,  -0.000000,-0.998476,-0.110222,0.986308, \
-0.000000,-0.998795,-0.098017,0.989177,  -0.000000,-0.999078,-0.085797,0.991710, \
-0.000000,-0.999322,-0.073565,0.993907,  -0.000000,-0.999529,-0.061321,0.995767, \
-0.000000,-0.999699,-0.049068,0.997290,  -0.000000,-0.999831,-0.036807,0.998476, \
-0.000000,-0.999925,-0.024541,0.999322,  -0.000000,-0.999981,-0.012272,0.999831
};