//
//  ofxToio.hpp
// 
//
//  Created by @_xhi, @kentoids, @kkshmz on 2017/09/03.
//
//


#include "ofMain.h"

class ofxToio{
    
public:
    
    ofxToio(void);
    virtual ~ofxToio();
    
    int x;
    int y;
    int id;
    int deg;
    float lastUpdate;
    
    bool isAlive(long now);
    ofVec2f aim(float tx, float ty);
    ofVec2f aim2(float tx, float ty);
    float distance(float ox, float oy);
    void setId(int i);
    int getId();
    ofVec3f getPos(void);
    int getUpdateTime();
    void setPos(int sx, int sy, int sdeg, float stime);
    
    
    
protected:
    
    

};

