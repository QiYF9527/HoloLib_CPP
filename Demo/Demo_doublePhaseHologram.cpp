// Demo_doublePhaseHologram.cpp --- ���ļ����� "main" ������
// ˫��λȫϢͼʾ��
//
#include "CComplexMat.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include "CGH.hpp"

using namespace cv;
using namespace gs;

static void help(const char** argv)
{
	printf("\n�˳�����ʾ��˫��λȫϢͼ�������Լ�����.\n"
		   "��ʾ�����ɵ�˫��λȫϢͼ�Լ��ع����������λ.\n"
		   "����·��:\n %s.\n", argv[0]);
}


int main(int argc, const char** argv)
{
	help(argv);

	if (argc != 3) // ����ʱ��ҪЯ��ͼƬ·������(��Ŀ����-����-�������-ͼƬ·��)
	{
		std::cout << " Usage: display_image ImageToLoadAndDisplay" << std::endl;
		return -1;
	}

	// �����������λͼ������ͼ��ֱ��ʡ��������͡����ݷ�Χ
	Mat amplitude = imread(argv[1], IMREAD_GRAYSCALE);
	Mat phase = imread(argv[2], IMREAD_GRAYSCALE);
	Size dsize = Size(800, 800);
	phase = Mat_<double>(phase);
	amplitude = Mat_<double>(amplitude);
	resize(amplitude, amplitude, dsize);
	resize(phase, phase, dsize);
	normalize(phase, phase, 0.0, 1.0, NORM_MINMAX);
	normalize(amplitude, amplitude, 0.0, 1.0, NORM_MINMAX);

	// ����˫��λȫϢͼ
	Mat hologram;
	getDoublePhaseHologram(amplitude, phase, hologram, 1);

	// ��ʾ˫��λȫϢͼ
	normalize(hologram, hologram, 0, 1, NORM_MINMAX);
	imshow("˫��λȫϢͼ", hologram);
	hologram = hologram * (2 * CV_PI);

	// �ع�˫��λȫϢͼ��������ʾ
	CComplexMat result(800, 800);
	recDoubleHologram(hologram, result, 200);
	Mat recAmplitude = result.getAmplitude();
	Mat recPhase = result.getPhase();
	normalize(recAmplitude, recAmplitude, 0, 1, NORM_MINMAX);
	normalize(recPhase, recPhase, 0, 1, NORM_MINMAX);
	imshow("���", recAmplitude);
	imshow("��λ", recPhase);
	waitKey(0);
}