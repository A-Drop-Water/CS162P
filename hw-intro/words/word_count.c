/*

Copyright © 2019 University of California, Berkeley

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

word_count provides lists of words and associated count

Functional methods take the head of a list as first arg.
Mutators take a reference to a list as first arg.
*/

#include "word_count.h"

/* Basic utilities */

void toLower(char** word)
{
  for(int i = 0;(*word)[i];++i)
  {
    if(isupper((*word)[i])) 
    {
      (*word)[i] = tolower((*word)[i]);
    }
  }
}

char *new_string(char *str) {
  char *new_str = (char *) malloc(strlen(str) + 1);
  if (new_str == NULL) {
    return NULL;
  }
  return strcpy(new_str, str);
}

int init_words(WordCount **wclist) {
  /* Initialize word count.
     Returns 0 if no errors are encountered
     in the body of this function; 1 otherwise.
  */
  *wclist = NULL;
  return 0;
}

ssize_t len_words(WordCount *wchead) {
  /* Return -1 if any errors are
     encountered in the body of
     this function.
  */
  //  when will errors happen and how to do with them?
    if(wchead == NULL) return -1;  

    size_t len = 0;

    while(tmp != NULL)
    {
      len++;s
      tmp = tmp->next;
    }
    return len;
}

WordCount *find_word(WordCount *wchead, char *word) {
  /* Return count for word, if it exists */
  WordCount *wc = wchead;

  // character should all be lowercase
  toLower(&word);

  // break when wc reaches end or wc >= word
  while(wc != NULL && (strcmp(wc->word,word) <  0))
  {
    wc = wc->next;
  }

  if(wc != NULL && strcmp(wc->word,word) == 0)
  {
    return wc;
  }

  // Not found
  return NULL;
}

int add_word(WordCount **wclist, char *word) {
  /* If word is present in word_counts list, increment the count.
     Otherwise insert with count 1.
     Returns 0 if no errors are encountered in the body of this function; 1 otherwise.
  */
  if(wclist == NULL || word == NULL)
  {
    return 1;
  }

  WordCount* tmp = *wclist;
  WordCount* pre = NULL;
  toLower(&word);

  // list is empty
  if(tmp == NULL)
  {
    tmp = (WordCount*) malloc(sizeof(WordCount));
    tmp->count = 1;
    tmp->word = new_string(word);
    tmp->next = NULL;
    *wclist   = tmp;
    return 0;
  }

  while(tmp != NULL && (strcmp(word,tmp->word) > 0))
  {
      pre = tmp;
      tmp = tmp->next;
  }
  
  // suppose doing tail insert
  // word is new
  if(tmp == NULL || (strcmp(word,tmp->word) < 0))
  {
    tmp = (WordCount*) malloc(sizeof(WordCount));
    tmp->count = 1;
    tmp->word = new_string(word);
    // edge condition when the list is empty
    if(pre == NULL)
    { 
      tmp->next = *wclist;
      *wclist = tmp;
      return 0;
    }

    tmp->next = pre->next;
    
    pre->next = tmp;

    return 0;
  }

  // word already exist
  tmp->count++; 
  return 0;
}

void fprint_words(WordCount *wchead, FILE *ofile) {
  /* print word counts to a file */
  WordCount *wc;
  for (wc = wchead; wc; wc = wc->next) {
    fprintf(ofile, "%i\t%s\n", wc->count, wc->word);
  }
}
  
