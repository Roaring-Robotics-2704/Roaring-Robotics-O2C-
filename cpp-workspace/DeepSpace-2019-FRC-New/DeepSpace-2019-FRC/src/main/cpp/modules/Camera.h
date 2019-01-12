/*
 * Camera.h
 *
 *  Created on: Mar 21, 2018
 *      Author: cryog
 */

#ifndef SRC_MODULES_CAMERA_H_
#define SRC_MODULES_CAMERA_H_

#define YELLOW_R_MIN 120
#define YELLOW_G_MIN 120
#define YELLOW_B_MAX 80

#define BLUE_R_MAX 80
#define BLUE_G_MAX 80
#define BLUE_B_MIN 120

#define RED_R_MIN 120
#define RED_G_MAX 80
#define RED_B_MAX 80

#define VERT_SCAN 160
#define VERT_SCAN_R 0
#define VERT_SCAN_B 0

class CameraModule : public Module{
private:
	static cv::Mat sC;
	static cv::Mat sR;
	static cv::Mat sB;
public:
	static void VisionThread()
    {
        CameraServer::GetInstance()->SetSize(CameraServer::kSize320x240);
        cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
        cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
        cs::CvSource outputStreamC = CameraServer::GetInstance()->PutVideo("Tracking Cube", 320, 240);
        cs::CvSource outputStreamR = CameraServer::GetInstance()->PutVideo("Tracking Red", 320, 240);
        cs::CvSource outputStreamB = CameraServer::GetInstance()->PutVideo("Tracking Blue", 320, 240);
        cs::CvSource outputStreamDrv = CameraServer::GetInstance()->PutVideo("Driver View", 320, 240);
        cv::Mat source;
        cv::Mat output;
        while(true) {
            if(cvSink.GrabFrame(source) == 0) continue;
            SmartDashboard::PutNumber("Source Rows", source.rows);
            SmartDashboard::PutNumber("Source Cols", source.cols);
            outputStreamDrv.PutFrame(source);

            cv::Mat c = vta(source.clone());
            cv::Mat r = vtr(source.clone());
            cv::Mat b = vtb(source.clone());

            outputStreamC.PutFrame(c);
            outputStreamR.PutFrame(r);
            outputStreamB.PutFrame(b);
        }
    }
    void ModuleInit()
    {
        std::thread visionThread(VisionThread);
        visionThread.detach();
    }


    static cv::Mat vta(cv::Mat source){
    	cv::Mat tmp1;
    	            cv::Mat tmp2;

    	            //cv::Mat tmpYellowL(320, 240, )
    	            cv::Vec3b * currentRowS;
    	            std::vector<int> lM;
    	            std::vector<int> rM;
    	            for (int j = VERT_SCAN; j < source.rows; ++j)
    	                {
    	            	int l = -1;
    	            	int r = -1;
    	            	bool p = true;
    	            	bool q = false;
    	                    currentRowS = source.ptr<cv::Vec3b>(j);
    	                    for (int i = 0; i < source.cols; ++i)
    	                    {
    	                    	bool a = currentRowS[i][0] < YELLOW_B_MAX && currentRowS[i][1] > YELLOW_G_MIN && currentRowS[i][2] > YELLOW_R_MIN;
    	                        if(a){
    	                        	q = true;
    									if(l == -1){
    										l = i;
    									}
    									r = i;
    	                        }
    	                    	currentRowS[i][0] = a * 255;
    	                        currentRowS[i][1] = a * 255;
    	                        currentRowS[i][2] = a * 255;

    	                    }
    	                    if(p && q){
    	                    	lM.push_back(l);
    	                    	rM.push_back(r);
    	                    }
    	                }
    	            int l = 0, r = 0;
    	            for(int a : lM){
    	            	l += a;
    	            }
    	            for(int a : rM){
    	            	r += a;
    	            }
    	            if(lM.size() != 0 && rM.size() != 0){
    					l /= lM.size();
    					r /= lM.size();
    					int x = (l + r) / 2;
    					for (int j = 0; j < source.rows; ++j)
    									{
    										currentRowS = source.ptr<cv::Vec3b>(j);
    										currentRowS[x][2] = 255;
    									}
    					currentRowS = source.ptr<cv::Vec3b>(VERT_SCAN);
    					for(int i = 0; i < source.cols; i++){
    						currentRowS[i][1] = 255;
    					}
    					CameraData::offset = (x - source.cols / 2.0) / (source.cols / 2.0);
    					CameraData::lOffset = CameraData::offset;
    					CameraData::civ = true;
    	            } else{
    	            	CameraData::offset = -CameraData::lOffset;
    					CameraData::civ = false;
    	            }
    	            return source;
    }


    static cv::Mat vtr(cv::Mat source){
    	cv::Mat tmp1;
    	            cv::Mat tmp2;

    	            //cv::Mat tmpYellowL(320, 240, )
    	            cv::Vec3b * currentRowS;
    	            std::vector<int> lM;
    	            std::vector<int> rM;
    	            for (int j = VERT_SCAN_R; j < source.rows; ++j)
    	                {
    	            	int l = -1;
    	            	int r = -1;
    	            	bool p = true;
    	            	bool q = false;
    	                    currentRowS = source.ptr<cv::Vec3b>(j);
    	                    for (int i = 0; i < source.cols; ++i)
    	                    {
    	                    	bool a = currentRowS[i][0] < RED_B_MAX && currentRowS[i][1] < RED_G_MAX && currentRowS[i][2] > RED_R_MIN;
    	                        if(a){
    	                        	q = true;
    									if(l == -1){
    										l = i;
    									}
    									r = i;
    	                        }
    	                    	currentRowS[i][0] = a * 255;
    	                        currentRowS[i][1] = a * 255;
    	                        currentRowS[i][2] = a * 255;

    	                    }
    	                    if(p && q){
    	                    	lM.push_back(l);
    	                    	rM.push_back(r);
    	                    }
    	                }
    	            int l = 0, r = 0;
    	            for(int a : lM){
    	            	l += a;
    	            }
    	            for(int a : rM){
    	            	r += a;
    	            }
    	            if(lM.size() != 0 && rM.size() != 0){
    					l /= lM.size();
    					r /= lM.size();
    					int x = (l + r) / 2;
    					for (int j = 0; j < source.rows; ++j)
    									{
    										currentRowS = source.ptr<cv::Vec3b>(j);
    										currentRowS[x][2] = 255;
    									}
    					currentRowS = source.ptr<cv::Vec3b>(VERT_SCAN);
    					for(int i = 0; i < source.cols; i++){
    						currentRowS[i][1] = 255;
    					}
    					CameraData::rOffset = (x - source.cols / 2.0) / (source.cols / 2.0);
    					CameraData::lrOffset = CameraData::rOffset;
    					CameraData::riv = true;
    	            } else{
    	            	CameraData::rOffset = -CameraData::lrOffset;
    					CameraData::riv = false;
    	            }
    	            return source;
    }


    static cv::Mat vtb(cv::Mat source){
    	cv::Mat tmp1;
    	            cv::Mat tmp2;

    	            //cv::Mat tmpYellowL(320, 240, )
    	            cv::Vec3b * currentRowS;
    	            std::vector<int> lM;
    	            std::vector<int> rM;
    	            for (int j = VERT_SCAN_B; j < source.rows; ++j)
    	                {
    	            	int l = -1;
    	            	int r = -1;
    	            	bool p = true;
    	            	bool q = false;
    	                    currentRowS = source.ptr<cv::Vec3b>(j);
    	                    for (int i = 0; i < source.cols; ++i)
    	                    {
    	                    	bool a = currentRowS[i][0] > BLUE_B_MIN && currentRowS[i][1] < BLUE_G_MAX && currentRowS[i][2] < BLUE_R_MAX;
    	                        if(a){
    	                        	q = true;
    									if(l == -1){
    										l = i;
    									}
    									r = i;
    	                        }
    	                    	currentRowS[i][0] = a * 255;
    	                        currentRowS[i][1] = a * 255;
    	                        currentRowS[i][2] = a * 255;

    	                    }
    	                    if(p && q){
    	                    	lM.push_back(l);
    	                    	rM.push_back(r);
    	                    }
    	                }
    	            int l = 0, r = 0;
    	            for(int a : lM){
    	            	l += a;
    	            }
    	            for(int a : rM){
    	            	r += a;
    	            }
    	            if(lM.size() != 0 && rM.size() != 0){
    					l /= lM.size();
    					r /= lM.size();
    					int x = (l + r) / 2;
    					for (int j = 0; j < source.rows; ++j)
    									{
    										currentRowS = source.ptr<cv::Vec3b>(j);
    										currentRowS[x][2] = 255;
    									}
    					currentRowS = source.ptr<cv::Vec3b>(VERT_SCAN);
    					for(int i = 0; i < source.cols; i++){
    						currentRowS[i][1] = 255;
    					}
    					CameraData::bOffset = (x - source.cols / 2.0) / (source.cols / 2.0);
    					CameraData::lbOffset = CameraData::bOffset;
    					CameraData::biv = true;
    	            } else{
    	            	CameraData::bOffset = -CameraData::lbOffset;
    					CameraData::biv = false;
    	            }
    	            return source;
    }
};


#endif /* SRC_MODULES_CAMERA_H_ */