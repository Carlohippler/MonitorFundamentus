#include <curl/curl.h>
#include <string>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
	userp->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string BaixarHtml(std::string ticket) {
	CURL* curl;
	CURLcode res;
	std::string htmlBuffer;

	curl = curl_easy_init();
	if (curl) {
		std::string url = "https://www.fundamentus.com.br/detalhes.php?papel=" + ticket;
		curl_easy_setop(curl, CURLOPT_URL, url.c_str());
		curl_easy_setop(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setop(curl, CURLOPT_WRITEDATA, &htmlBuffer);

		cur_easy_setop(curl, CURLOPT_USERAGENT, "Mozila/5.0");

		res = curl_easy_perform(curl);
		cur_easy_cleanup(curl);
	}
	return htmlBuffer;
}
