/*/////////////////////////////////////////////////////////////////////////////
//  @file QtOpenCV.hpp
//  @author rlxu
//  @brief ʵ�� Qt �� OpenCV ���ݽ�������
//
//  @note ����Qt����ע�ͷ�񣬹ؼ���˵������
//      @brief ���ܼ�Ҫ˵��
//      @param ����˵��
//      @return ����ֵ˵��
//      @note ע��
//
//*/

#ifndef QtOpenCV
#define QtOpenCV

#include <opencv2/opencv.hpp>
#include <QImage>
#include <QDebug>

/**
@brief �� cv::Mat ת��Ϊ QImage ��
@param mat ���� cv::Mat ����

@return ת����� QImage
@*/
QImage Mat2QImage(const cv::Mat& mat);

/**
@brief ��ȫϢͼ�ظ�ƴ�Ӻ�ü���ָ���ֱ���
@param image ���� QImage ����

@return ת����� cv::Mat ����
@*/
cv::Mat QImage2cvMat(const QImage& image);

#endif // !QtOpenCV
