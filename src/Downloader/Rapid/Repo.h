/* This file is part of pr-downloader (GPL v2 or later), see the LICENSE file */

#ifndef REPO_H
#define REPO_H


#include <list>
#include <string>

class CSdp;
class CRapidDownloader;
class IDownload;

class CRepo
{
	std::string repourl;
	CRapidDownloader* rapid;
public:
	CRepo(const std::string& repourl, CRapidDownloader* rapid);
	~CRepo();

	/**
		returns download for a repo file
			returns true if file needs to be downloaded
	*/
	bool getDownload(IDownload& dl);

	/**
	parse a repo file (versions.gz)
	a line looks like
	nota:revision:1,52a86b5de454a39db2546017c2e6948d,,NOTA test-1

	<tag>,<md5>,<depends on (descriptive name)>,<descriptive name>
	*/
	bool parse();
private:
	std::list<CSdp*> sdps;
	std::string tmpFile;
};

#endif
