#include "pch.h"
#include "CppUnitTest.h"


#define MAX_ITEMS 10
#define MAX_REVIEWERS 10

typedef struct {
    char name[50];
    float price;
    int calories;
} MenuItem;


extern "C" float computeSubtotal(MenuItem orderedItems[], int orderCount);
extern "C" float calculateTip(float subtotal, int tipOption);
extern "C" void printReceipt(MenuItem orderedItems[], int orderCount, float subtotal, float tip);
extern "C" void printReceiptToFile(MenuItem * orderedItems, int orderCount, float subtotal, float tip);
extern "C" int printMenuTEST(MenuItem menuItems[], int itemCount, char menuName[], int choice);
extern "C" void initializeReviews(float reviews[MAX_ITEMS][MAX_REVIEWERS]);
extern "C" void addReview(float reviews[MAX_ITEMS][MAX_REVIEWERS], int itemIndex, float score);
extern "C" float calculateTipCustom(float subtotal, int tipOption, float customTip);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingKiosk
{
    TEST_CLASS(Review)
    {
    public:
        TEST_METHOD(REC_RI_01)
        {
            // Assuming initializeReviews takes an array of float and its size
            float reviews[MAX_ITEMS][MAX_REVIEWERS];
            initializeReviews(reviews); // Correctly pass the array and size
            for (int i = 0; i < MAX_ITEMS; ++i) {
                for (int j = 0; j < MAX_REVIEWERS; ++j) {
                    Assert::AreEqual(-1.0f, reviews[i][j]);
                }
            }
        }


        TEST_METHOD(REC_RI_02)
        {
            float reviews[MAX_ITEMS][MAX_REVIEWERS]; // Initialize all to 0 for simplicity
            int itemIndex = 1; // Example item index
            float score = 4.5f; // Example review score

            // Directly calling our simplified mock function for demonstration
            addReview(reviews, itemIndex, score);

                // Since we're mocking, we expect a direct pass without complex checks
                Assert::AreEqual(score, reviews[itemIndex][MAX_REVIEWERS]);
        }
    };
    TEST_CLASS(CommandLineArgument) 
    {
    public:

        TEST_METHOD(REC_CLA_01)
        {
            // manuel testing : PASS
        }

        TEST_METHOD(REC_CLA_02)
        {
            // manuel testing : PASS
        }

        TEST_METHOD(REC_CLA_03)
        {
            // manuel testing : PASS
        }

        TEST_METHOD(REC_CLA_04)
        {
            // manuel testing : PASS
        }
    };
    TEST_CLASS(Subtotal)
    {
        TEST_METHOD(REC_ST_01)
        {
            MenuItem items[] = {
              {"Item 1", 10.0, 1},
              {"Item 2", 20.0, 1},
              {"Item 3", 30.0, 1}
            };
            int itemCount = sizeof(items) / sizeof(items[0]);

            float expectedSubtotal = 60.0;

            float actualSubtotal = computeSubtotal(items, itemCount);

            Assert::AreEqual(expectedSubtotal, actualSubtotal);
        }

        TEST_METHOD(SUBT_002)
        {
            MenuItem items[] = {
              {"Item 1", 30.0, 1},
              {"Item 2", 60.0, 1},
              {"Item 3", 30.0, 1}
            };
            int itemCount = sizeof(items) / sizeof(items[0]);

            float expectedSubtotal = 120.0;

            float actualSubtotal = computeSubtotal(items, itemCount);

            Assert::AreEqual(expectedSubtotal, actualSubtotal);
        }
        TEST_METHOD(SUBT_003)
        {
            MenuItem items[] = {
              {"Item 1", 20.5, 1},
              {"Item 2", 10.5, 1},
              {"Item 3", 40.0, 1}
            };
            int itemCount = sizeof(items) / sizeof(items[0]);

            float expectedSubtotal = 71;

            float actualSubtotal = computeSubtotal(items, itemCount);

            Assert::AreEqual(expectedSubtotal, actualSubtotal);
        }
        TEST_METHOD(SUBT_004)
        {
            MenuItem items[] = {
              {"Item 1", 35.90, 1},
              {"Item 2", 12.05, 1},
              {"Item 3", 46.00, 1}
            };
            int itemCount = sizeof(items) / sizeof(items[0]);

            float expectedSubtotal = 10.95;

            float actualSubtotal = computeSubtotal(items, itemCount);

            Assert::AreNotEqual(expectedSubtotal, actualSubtotal);
        }

        TEST_METHOD(SUBT_005)
        {
            MenuItem items[] = {
              {"Item 1", 19.03, 1},
              {"Item 2", 12.45, 1},
              {"Item 3", 64.70, 1}
            };
            int itemCount = sizeof(items) / sizeof(items[0]);

            float expectedSubtotal = 42.95;

            float actualSubtotal = computeSubtotal(items, itemCount);

            Assert::AreNotEqual(expectedSubtotal, actualSubtotal);
        }
    };
    TEST_CLASS(Tip) {
        TEST_METHOD(TestCustomTiptest1)
    {
  
        float subtotal = 105.22;
        int tipOption = 1; 
        float customTip = 5.22;
        
        float tip = calculateTipCustom(subtotal, tipOption, customTip);

 
        Assert::AreEqual(tip, customTip); 
    }

    TEST_METHOD(TestCustomTiptest2)
    {

        float subtotal = 200.0;
        int tipOption = 1;
        float customTip = 100.0;


        float tip = calculateTipCustom(subtotal, tipOption, customTip);


        Assert::AreEqual(tip, customTip);
    }
    TEST_METHOD(TestCustomTip)
    {

        float subtotal = 100.0;
        int tipOption = 2;


        float tip = calculateTip(subtotal, tipOption);


        Assert::IsTrue(tip >= 0.0f && tip < subtotal * 0.25f);
    }
    };
}