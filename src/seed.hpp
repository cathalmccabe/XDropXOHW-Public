//==================================================================
// Title:  C++ x-drop seed-and-extend alignment algorithm
//==================================================================

#include<algorithm> 
#include<cassert>

template<typename Tx_>
const Tx_&  min_fpga(const Tx_& _Left, const Tx_& Right_)
{   // return smaller of _Left and Right_
    if (_Left < Right_)
        return _Left;
    else
        return Right_;
}

template<typename Tx_, typename Ty_>
Tx_  min_fpga(const Tx_& _Left, const Ty_& Right_)
{   // return smaller of _Left and Right_
    return (Right_ < _Left ? Right_ : _Left);
}
template<typename Ty_>
Ty_ const &
  max_fpga(const Ty_& _Left, const Ty_& Right_)
{   // return larger of _Left and Right_
    if (_Left < Right_)
        return Right_;
    else
        return _Left;
}

template<typename Tx_, typename Ty_>
Tx_
  max_fpga(const Tx_& _Left, const Ty_& Right_)
{   // return smaller of _Left and Right_
    return (Right_ < _Left ? _Left : Right_);
}


struct SeedL
{
	int beginPositionH;
	int beginPositionV;
	int endPositionH;
	int endPositionV;
	int seedLength;
	int lowerDiagonal; 
	int upperDiagonal; 
	int beginDiagonal;
	int endDiagonal;
	int score;
	int fillForFPGA[6];

	SeedL(): beginPositionH(0), beginPositionV(0), endPositionH(0), endPositionV(0), lowerDiagonal(0), upperDiagonal(0), score(0)
	{}

	SeedL(int beginPositionH, int beginPositionV, int seedLength):
		beginPositionH(beginPositionH), beginPositionV(beginPositionV), endPositionH(beginPositionH + seedLength),
		endPositionV(beginPositionV + seedLength), lowerDiagonal((beginPositionH - beginPositionV)),
		upperDiagonal((beginPositionH - beginPositionV)), beginDiagonal(beginPositionH - beginPositionV),
		endDiagonal(endPositionH - endPositionV), score(0)
	{
		assert(upperDiagonal >= lowerDiagonal);
	}

	SeedL(int beginPositionH, int beginPositionV, int endPositionH, int endPositionV):
		beginPositionH(beginPositionH),
		beginPositionV(beginPositionV),
		endPositionH(endPositionH),
		endPositionV(endPositionV),
		lowerDiagonal(min_fpga((beginPositionH - beginPositionV), (endPositionH - endPositionV))),
		upperDiagonal(max_fpga((beginPositionH - beginPositionV), (endPositionH - endPositionV))),
		beginDiagonal((beginPositionH - beginPositionV)),
		endDiagonal((endPositionH - endPositionV)),
		score(0)
	{
		assert(upperDiagonal >= lowerDiagonal);
	}

	  SeedL(SeedL const& other):
		beginPositionH(other.beginPositionH),
		beginPositionV(other.beginPositionV),
		endPositionH(other.endPositionH),
		endPositionV(other.endPositionV),
		lowerDiagonal(other.lowerDiagonal),
		upperDiagonal(other.upperDiagonal),
		beginDiagonal(other.beginDiagonal),
		endDiagonal(other.endDiagonal),
		score(0)
	{
		assert(upperDiagonal >= lowerDiagonal);
	}

};

struct Result
{
	SeedL myseed;
	int score; 			// alignment score
	int length;			// overlap length / max extension

	Result() : score(0), length(0)//check
	{
		//myseed=SeedL();
	}

	Result(int kmerLen) : score(0), length(kmerLen)
	{
		//myseed=SeedL();
	}

};

int
 getAlignScore(SeedL const &myseed){
	return myseed.score;
}

int
  getBeginPositionH(SeedL const &myseed){
	return myseed.beginPositionH;
}

int
  getBeginPositionV(SeedL const &myseed){
	return myseed.beginPositionV;
}

int
  getEndPositionH(SeedL const &myseed){
	return myseed.endPositionH;
}

int
  getEndPositionV(SeedL const &myseed){
	return myseed.endPositionV;
}

int
 getSeedLLength(SeedL const &myseed){
	return myseed.seedLength;
}

int
 getLowerDiagonal(SeedL const &myseed){
	return myseed.lowerDiagonal;
}

int
 getUpperDiagonal(SeedL const &myseed){
	return myseed.upperDiagonal;
}

int
 getBeginDiagonal(SeedL const &myseed){
	return myseed.beginDiagonal;
}

int
 getEndDiagonal(SeedL const &myseed){
	return myseed.endDiagonal;
}

void
 setAlignScore(SeedL &myseed,int const value){
	myseed.score = value;
}

void
  setBeginPositionH(SeedL &myseed,int const value){
	myseed.beginPositionH = value;
}

void
  setBeginPositionV(SeedL &myseed,int const value){
	myseed.beginPositionV = value;
}

void
  setEndPositionH(SeedL &myseed,int const value){
	myseed.endPositionH = value;
}

void
  setEndPositionV(SeedL &myseed,int const value){
	myseed.endPositionV = value;
}

void
  setSeedLLength(SeedL &myseed,int const value){
	myseed.seedLength = value;
}

void
  setLowerDiagonal(SeedL &myseed,int const value){
	myseed.lowerDiagonal = value;
}

void
  setUpperDiagonal(SeedL &myseed,int const value){
	myseed.upperDiagonal = value;
}

void
  setBeginDiagonal(SeedL &myseed,int const value){
	myseed.beginDiagonal = value;
}

void
  setEndDiagonal(SeedL &myseed,int const value){
	myseed.endDiagonal = value;
}
