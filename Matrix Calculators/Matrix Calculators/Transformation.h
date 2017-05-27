#pragma once
class CTransformation
{
public:
	~CTransformation();

	static CTransformation& GetInstance();

	//void SetResultantMat(float _rgInputMat[4][4]);
	void ApplyScaling(float _X, float _Y, float _Z, float _rgResultMat[4][4]);
	void CreateIdentatyMatrix(float _rgMatrix[4][4]);

private:

	CTransformation();
	CTransformation(const CTransformation& _kr);
	CTransformation& operator=(const CTransformation& _kr);

	void MultiplyMatrix(float _rgInputMat[4][4], float _rgResultMat[4][4]);
	float m_rgfResultantMat[4][4] = {
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } };

	float m_rgfTempMat[4][4] = {
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } };

protected:
	static CTransformation* s_pTransformation;
};

